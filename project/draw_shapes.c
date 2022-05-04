#include "draw_shapes.h"    
#include "switches.h"

// axis zero for col, axis 1 for row
short drawPos[2] = {10,10}, controlPos[2] = {10,10};
short velocity[2] = {3,8}, limits[2] = {screenWidth-36, screenHeight-8};

short redrawScreen = 1;
char sonicstate = 1;
char curr_state = 0;
int blink_limit = 35;
char color =0;

u_int controlFontColor = COLOR_GREEN;


void
update_shape(void)
{
  static unsigned char row = screenHeight / 2, col = screenWidth / 2;
  static char blue = 31, green = 0, red = 31;
  static unsigned char step = 0;
  if (switches & SW4) return;
  if (step <= 60) {
    int startCol = col - step;
    int endCol = col + step;
    int width = 1 + endCol - startCol;
    // a color in this BGR encoding is BBBB BGGG GGGR RRRR
    unsigned int color = (blue << 11) | (green << 5) | red;
    fillRectangle(startCol, row+step, width, 1, color);
    fillRectangle(startCol, row-step, width, 1, color);
    if (switch3_down) green = (green + 1) % 64;
    if (switch2_down) blue = (blue + 2) % 32;
    if (switch1_down) red = (red - 3) % 32;
    step ++;
  } else {
     clearScreen(COLOR_BLUE);
     step = 0;
  }
}

void sonic_move(void)
{
    if (blink_limit>30){
        if (sonicstate){
            drawSonic(64,64);
            drawString11x16(10,5,"SONIC", COLOR_BLACK, COLOR_BLUE);
        }
        else {
            drawSonic2(64,64);
            drawString11x16(10,5,"SONIC", COLOR_GREEN, COLOR_BLUE);
        }
    }
    else{
        blink_limit = 100;
    drawString11x16(5,130,"UR 2 SLOW", COLOR_RED, COLOR_BLUE);
    }
}

void draw_diamond(char center,char height, u_int shapeColor)
{
    for (u_char r = 0; r<11; r++){
        for(u_char c = 0; c<=r; c++){
            drawPixel(center+c, height+r, shapeColor);
            drawPixel(center-c, height+r, shapeColor);
        }
    }
    for (u_char c = 0; c<11; c++){
        for(u_char r = 10; r<=20-c; r++){
            drawPixel(center+c, height+r, shapeColor);
            drawPixel(center-c, height+r, shapeColor);
        }
    }
}
