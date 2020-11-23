#ifndef ACTUATOR_H
#define ACTUATOR_H

class Actuator {
public:
  virtual void forward() = 0;
  virtual void back() = 0;
  virtual void stop() = 0;

  virtual void turnRight() = 0;
  virtual void turnLeft() = 0;
};

#endif // ACTUATOR_H
