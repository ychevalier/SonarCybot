/*
 * Cybot Driver Unit
 * 
 * 1 - RH motor forwards. 
 * 2 - RH motor backwards. 
 * 3 - LH motor forwards.
 * 4 - LH motor backwards. 
 * 5 - 5 volts to uP.
 * 6 - 6 volts.
 * 7 - ground.
 * 
 *  ------------------------------------------
 * |  1  |  2  |  3  |  4  |  5  |  6  |  7  |
 * -------------------------------------------
 * | D5  | D6  |  D7 |  D8 |     | 5V  | GND |
 * -------------------------------------------
 * 
 * Somehow, 5V isn't enough for Wemos D1 mini, you need the 6V pin.
 * 
 */

#ifndef PINCONF_H
#define PINCONF_H

#ifdef WEMOS_BOARD

#define TRIG D3
#define ECHO_LEFT D2
#define ECHO_RIGHT D1

#define RH_FORWARD D5
#define RH_BACKWARD D6

#define LH_FORWARD D7
#define LH_BACKWARD D8

#endif

#ifdef ARDUINO_THINGY

#define TRIG 1
#define ECHO_LEFT 2
#define ECHO_RIGHT 3

#define RH_FORWARD 4
#define RH_BACKWARD 5

#define LH_FORWARD 6
#define LH_BACKWARD 7

#endif

#endif // PINCONF_H