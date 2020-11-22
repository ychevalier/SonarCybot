#ifndef THINKER_H
#define THINKER_H

#include "Sensor.h"
#include "Actuator.h"

#include "Logger.h"

class DummyLogger : public Logger {
public:
  void log(int message) override {}
  void log(const char* message) override {}
};

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
