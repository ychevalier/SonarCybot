#ifndef REMOTETHINKER_H
#define REMOTETHINKER_H

#include "framework/Thinker.h"

#include "utils/logger.h"

class RemoteThinker : public Thinker {
public:
  RemoteThinker(Sensor* sensor, Actuator* actuator, Logger* logger = new DummyLogger());

  void run() override;

private:
  Logger* logger;
};

#endif // REMOTETHINKER_H
