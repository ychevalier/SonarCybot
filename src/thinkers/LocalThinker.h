#ifndef LOCALTHINKER_H
#define LOCALTHINKER_H

#include "framework/Thinker.h"

#include "utils/logger.h"

class LocalThinker : public Thinker {
public:
  LocalThinker(Sensor* sensor, Actuator* actuator, Logger* logger = new DummyLogger());

  void run() override;

private:
  Logger* logger;
};

#endif // LOCALTHINKER_H
