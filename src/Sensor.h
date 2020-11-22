#ifndef SENSOR_H
#define SENSOR_H

#define UNDEFINED_PROPERTY -1

class Sensor {
public:
  virtual void acquire() = 0;

  virtual int getDistanceFront() const {
    return UNDEFINED_PROPERTY;
  }
  
  virtual int getDistanceRight() const {
    return UNDEFINED_PROPERTY;
  }
  
  virtual int getDistanceLeft() const {
    return UNDEFINED_PROPERTY;
  }
  
  virtual int getDistanceBack() const {
    return UNDEFINED_PROPERTY;
  }
};

#endif // SENSOR_H
