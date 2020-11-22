#ifndef THINKER_H
#define THINKER_H

#include "Sensor.h"
#include "Actuator.h"

#include "Logger.h"

class Thinker {
public:
  Thinker(Sensor* sensor, Actuator* actuator, Logger* logger = new DummyLogger());

  void run();

private:
  Sensor *sensor;
  Actuator *actuator;

  Logger *logger;
};

#endif // THINKER_H
