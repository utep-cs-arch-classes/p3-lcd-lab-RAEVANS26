#ifndef _DRAW_SHAPES_H_
#define _DRAW_SHAPES_H_

#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "switches.h"

extern short redrawScreen;
extern char sonicstate, curr_state, blink_limit;

/* draws an hourglass shape */
void update_shape(void);
void sonic_move(void);
void draw_diamond(char center, char height, u_int shapeColor);

#endif // _DRAW_SHAPES_H_
