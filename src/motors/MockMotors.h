#ifndef MOCKMOTORS_H
#define MOCKMOTORS_H

#include "framework/actuator.h"

class MockMotors : public Actuator {
public:
  void forward() override {};
  void back() override {};
  void stop() override {};
  void turnRight() override {};
  void turnLeft() override {};
};

#endif // MOCKMOTORS_H
