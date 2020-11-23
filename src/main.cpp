/**
 * 
 * 
 */

#include <Arduino.h>

#include "sensors/DoubleSonar.h"
#include "motors/CybotMotors.h"

#include "utils/logging/SerialLogger.h"
#include "utils/logging/MultiLogger.h"

#include "thinkers/LocalThinker.h"

#include "PinConf.h"

DoubleSonar sonars(TRIG, ECHO_RIGHT, ECHO_LEFT);
CybotMotors motors(RH_FORWARD, RH_BACKWARD, LH_FORWARD, LH_BACKWARD);

SerialLogger logger;

LocalThinker thinker(&sonars, &motors, &logger);

void setup () {
  
}

void loop () {
  thinker.run();
  delay(500);
}