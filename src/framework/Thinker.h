#ifndef THINKER_H
#define THINKER_H

#include "framework/Sensor.h"
#include "framework/Actuator.h"

class Thinker {
public:
  Thinker(Sensor* sensor, Actuator* actuator)
  : sensor(sensor)
  , actuator(actuator) {};

  virtual void run();

protected:
  Sensor *sensor;
  Actuator *actuator;
};

#endif // THINKER_H
