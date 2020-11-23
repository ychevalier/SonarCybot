#ifndef DOUBLESONAR_H
#define DOUBLESONAR_H

#include "framework/Sensor.h"

#include <Arduino.h>
#include <HCSR04.h>
#include <Ultrasonic.h>

// #define LIB_1

class DoubleSonar : public Sensor {
public:
  /**
   * @param triggerPin Digital pin that is used to send sonar wave (OUTPUT)
   * @param rightEchoPin Digital pin that is used to receive right sonar echo (INPUT)
   * @param leftEchoPin Digital pin that is used to receive left sonar echo (INPUT)
   */
  DoubleSonar(int triggerPin, int rightEchoPin, int leftEchoPin);

  void acquire() override;

  int getDistanceRight() const override;
  int getDistanceLeft() const override;

private:
#ifdef LIB_1
  UltraSonicDistanceSensor distanceSensorLeft;
  UltraSonicDistanceSensor distanceSensorRight;
#else
  Ultrasonic distanceSensorLeft;
  Ultrasonic distanceSensorRight;
#endif

  int distanceRight;
  int distanceLeft;
};

#endif // DOUBLESONAR_H
