#ifndef MOTORS_H
#define MOTORS_H

class Motors {
public:
  virtual void forward() = 0;
  virtual void back() = 0;
  virtual void stop() = 0;

  virtual void turnRight() = 0;
  virtual void turnLeft() = 0;
};

#endif // MOTORS_H
