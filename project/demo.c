#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"
#include "buzzer.h"

// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 

void main()
{
  
  P1DIR |= LED;		/**< Led on when CPU on */
  P1OUT |= LED;
  configureClocks();
  lcd_init();
  switch_init();
  buzzer_init();
  
  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	              /**< GIE (enable interrupts) */
  
  clearScreen(COLOR_BLUE);
  while (1) {			/* forever */
    if (redrawScreen) {
        redrawScreen = 0;
        switch (curr_state){
            case 0:// displays sonic moving
                sonic_move();
                break;
            case 1:
                blink_limit = 250;//changes color every second
                color_diamond();
                break;
            case 2:
                break;
            case 3:
                  clearScreen(COLOR_BLACK);
                break;
        }
      
    }
    P1OUT &= ~LED;	/* led off */
    or_sr(0x10);	/**< CPU OFF */
    P1OUT |= LED;	/* led on */
  }
}
