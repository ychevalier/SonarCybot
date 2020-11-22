#include "Thinker.h"

#include <Arduino.h>

#define MIN_DISTANCE 40

Thinker::Thinker(Sensor* sensor, Actuator* actuator, Logger* logger)
: sensor(sensor)
, actuator(actuator)
, logger(logger) {    
  // no op
}

void printDistance(Logger* logger, double distanceRight, double distanceLeft) {
  logger->log(distanceRight);
  logger->log(" - ");
  logger->log(distanceLeft);
  logger->log("\n");
}

void Thinker::run()
{
  sensor->acquire();

  int distanceRight = sensor->getDistanceRight();
  int distanceLeft = sensor->getDistanceLeft();

  printDistance(logger, distanceRight, distanceLeft);

  bool somethingRight = distanceRight > 1 && distanceRight < MIN_DISTANCE;
  bool somethingLeft = distanceLeft > 1 && distanceLeft < MIN_DISTANCE;

  if (somethingRight && somethingLeft)
  {
    logger->log("Detection Front\n");
    actuator->back();
  }
  else if (somethingRight)
  {
    logger->log("Detection Right\n");
    actuator->turnLeft();
  }
  else if (somethingLeft)
  {
    logger->log("Detection Left\n");
    actuator->turnRight();
  }
  else {
    actuator->forward();
  }
}