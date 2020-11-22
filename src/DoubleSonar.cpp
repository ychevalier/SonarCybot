#include "DoubleSonar.h"

DoubleSonar::DoubleSonar(int triggerPin, int rightEchoPin, int leftEchoPin)
: distanceSensorLeft(triggerPin, leftEchoPin)
, distanceSensorRight(triggerPin, rightEchoPin) {
  // no op
}

void DoubleSonar::acquire() {
#ifdef LIB_1
  distanceRight = distanceSensorRight.measureDistanceCm();
  distanceLeft = distanceSensorLeft.measureDistanceCm();
#else
  distanceRight = distanceSensorRight.read();
  distanceLeft = distanceSensorLeft.read();
#endif
}

int DoubleSonar::getDistanceRight() const {
  return distanceRight;
}

int DoubleSonar::getDistanceLeft() const {
  return distanceLeft;
}