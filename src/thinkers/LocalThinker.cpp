#include "LocalThinker.h"

#define MIN_DISTANCE 40

LocalThinker::LocalThinker(Sensor* sensor, Actuator* actuator, Logger* logger) 
: Thinker(sensor, actuator)
, logger(logger) {    
  // no op
}

void printDistance(Logger* logger, double distanceRight, double distanceLeft) {
  logger->log(distanceRight);
  logger->log(" - ");
  logger->log(distanceLeft);
  logger->log("\n");
}

void LocalThinker::run()
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