/*
 * Cybot Driver Unit
 * 
 * 1 - RH motor forwards. 
 * 2 - RH motor backwards. 
 * 3 - LH motor forwards.
 * 4 - LH motor backwards. 
 * 5 - 5 volts to uP.
 * 6 - 6 volts.
 * 7 - ground.
 * 
 *  ------------------------------------------
 * |  1  |  2  |  3  |  4  |  5  |  6  |  7  |
 * -------------------------------------------
 * | D5  | D6  |  D7 |  D8 |     | 5V  | GND |
 * -------------------------------------------
 * 
 * Somehow, 5V isn't enough for Wemos D1 mini, you need the 6V pin.
 * 
 */

#include <Arduino.h>
#include <HCSR04.h>
#include <Ultrasonic.h>

#define TRIG D3
#define ECHO_LEFT D2
#define ECHO_RIGHT D1

#define RH_FORWARD D5
#define RH_BACKWARD D6

#define LH_FORWARD D7
#define LH_BACKWARD D8

#define MIN_DISTANCE 40

// #define LIB_1

#ifdef LIB_1
UltraSonicDistanceSensor distanceSensorLeft(TRIG, ECHO_LEFT);
UltraSonicDistanceSensor distanceSensorRight(TRIG, ECHO_RIGHT);
#else
Ultrasonic distanceSensorLeftBis(TRIG, ECHO_LEFT);
Ultrasonic distanceSensorRightBis(TRIG, ECHO_RIGHT);
#endif

void reset() {
  digitalWrite(RH_FORWARD, LOW);
  digitalWrite(RH_BACKWARD, LOW);
  digitalWrite(LH_FORWARD, LOW);
  digitalWrite(LH_BACKWARD, LOW);
}

void forward() {
  Serial.println("Forward");
  reset();
  digitalWrite(RH_FORWARD, HIGH);
  digitalWrite(LH_FORWARD, HIGH);
}

void turnLeft() {
  Serial.println("Turn Left");
  reset();
  digitalWrite(RH_FORWARD, HIGH);
  digitalWrite(LH_BACKWARD, HIGH);
  delay(500);
  reset();
}

void turnRight() {
  Serial.println("Turn Right");
  reset();
  digitalWrite(LH_FORWARD, HIGH);
  digitalWrite(RH_BACKWARD, HIGH);
  delay(500);
  reset();
}

void back() {
  Serial.println("Back");
  reset();
  digitalWrite(LH_BACKWARD, HIGH);
  digitalWrite(RH_BACKWARD, HIGH);
  delay(1000);
  reset();
}

void setup () {
  Serial.begin(9600);

  pinMode(RH_FORWARD, OUTPUT);
  pinMode(RH_BACKWARD, OUTPUT);
  pinMode(LH_FORWARD, OUTPUT);
  pinMode(LH_BACKWARD, OUTPUT);
  reset();
}

void printDistance(double distanceRight, double distanceLeft) {
  Serial.print(distanceRight);
  Serial.print(" - ");
  Serial.println(distanceLeft);
}

void loop () {
#ifdef LIB_1
  double distanceRight = distanceSensorRight.measureDistanceCm();
  double distanceLeft = distanceSensorLeft.measureDistanceCm();
#else
  int distanceRight = distanceSensorRightBis.read();
  int distanceLeft = distanceSensorLeftBis.read();
#endif

  printDistance(distanceRight, distanceLeft);

  bool somethingRight = distanceRight > 1 && distanceRight < MIN_DISTANCE;
  bool somethingLeft = distanceLeft > 1 && distanceLeft < MIN_DISTANCE;

  if (somethingRight && somethingLeft)
  {
    Serial.println("Detection Front");
    back();
  }
  else if (somethingRight)
  {
    Serial.println ("Detection Right");
    turnLeft();
  }
  else if (somethingLeft)
  {
    Serial.println ("Detection Left");
    turnRight();
  }
  else {
    forward();
  }
  
  delay(500);
}