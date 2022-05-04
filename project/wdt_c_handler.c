#include "draw_shapes.h"
#include "switches.h"
#include "notes.h"
#include "buzzer.h"

/* the interupt handler for the watchdog timer */
void wdt_c_handler(void)
{
    static int secCount = 0;

    secCount ++;
    if (switch1_down==1){
        buzzer_set_period(G);
    }
    else if (switch2_down==1){
        buzzer_set_period(D);
    }
    else if (switch3_down==1){
        buzzer_set_period(F);
    }
    else if (switch4_down==1){
        buzzer_set_period(E);
    }
    else if (secCount >= 75) {		/* 10/sec */
    secCount = 0;
    redrawScreen = 1;
    sonicstate = !sonicstate;
    }
    else{
        buzzer_set_period(0);
    }

}
  
