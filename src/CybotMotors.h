#ifndef CYBOTMOTORS_H
#define CYBOTMOTORS_H

#include "Motors.h"

class CybotMotors : public Motors {
public:
  /**
   * @param rightForwardPin Digital pin that is used to enable right motor forward (OUTPUT)
   * @param rightBackwardPin Digital pin that is used to enable right motor backward (OUTPUT)
   * @param leftForwardPin Digital pin that is used to enable left motor forward (OUTPUT)
   * @param leftBackwardPin Digital pin that is used to enable left motor backward (OUTPUT)
   */
  CybotMotors(int rightForwardPin, int rightBackwardPin, int leftForwardPin, int leftBackwardPin);

  void forward() override;
  void back() override;
  void stop() override;
  void turnRight() override;
  void turnLeft() override;

protected:
  void reset();

private:
  int rightForwardPin;
  int rightBackwardPin; 
  int leftForwardPin;
  int leftBackwardPin;
};

#endif // CYBOTMOTORS_H
