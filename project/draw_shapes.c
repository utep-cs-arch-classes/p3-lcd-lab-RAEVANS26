#include "draw_shapes.h"    
#include "switches.h"

short redrawScreen = 1;
char sonicstate = 1;
char curr_state = 0;
int blink_limit = 35;
char color =0;

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
