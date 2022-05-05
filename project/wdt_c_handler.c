#include "draw_shapes.h"
#include "switches.h"
#include "notes.h"
#include "buzzer.h"

void wdt_c_handler(void)
{
    static int secCount = 0;

    secCount ++;
    if (switch1_down==1){
        buzzer_set_period(G);
        curr_state=0;
        blink_limit -= 5;
    }
    else if (switch2_down==1){
        buzzer_set_period(D);
        curr_state=1;
    }
    else if (switch3_down==1){
        buzzer_set_period(F);
        curr_state=2;
    }
    else if (switch4_down==1){
        buzzer_set_period(E);
        curr_state=3;
    }
    else if (secCount >= blink_limit) {		
    secCount = 0;
    redrawScreen = 1;
    sonicstate = !sonicstate;
    }
    else{
        buzzer_set_period(0);
    }

}
  
