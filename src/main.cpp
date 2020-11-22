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

#include <Arduino.h>

#include "DoubleSonar.h"
#include "CybotMotors.h"
#include "SerialLogger.h"

#include "Thinker.h"

#define TRIG D3
#define ECHO_LEFT D2
#define ECHO_RIGHT D1

#define RH_FORWARD D5
#define RH_BACKWARD D6

#define LH_FORWARD D7
#define LH_BACKWARD D8

DoubleSonar sonars(TRIG, ECHO_RIGHT, ECHO_LEFT);
CybotMotors motors(RH_FORWARD, RH_BACKWARD, LH_FORWARD, LH_BACKWARD);

SerialLogger logger;

Thinker thinker(&sonars, &motors, &logger);

void setup () {
  
}

void loop () {
  thinker.run();
  delay(500);
}