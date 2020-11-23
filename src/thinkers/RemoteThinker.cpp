#include "RemoteThinker.h"

#include "utils/Logger.h"

RemoteThinker::RemoteThinker(Sensor* sensor, Actuator* actuator, Logger* logger)
: Thinker(sensor, actuator)
, logger(logger) {    
  // no op
}

void RemoteThinker::run()
{
  logger->log("Not implemented yet");
}