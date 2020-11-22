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
#include <ESP8266WiFi.h>

#include "Motors.h"
#include "CybotMotors.h"

// Network SSID
#define SSID "Ruche"
#define PASSWORD "zZuZ51F4N1MiZfv5"

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

CybotMotors motors(RH_FORWARD, RH_BACKWARD, LH_FORWARD, LH_BACKWARD);

void setup () {
  Serial.begin(9600);

  // Connect WiFi
  WiFi.hostname("Robot");
  WiFi.begin(SSID, PASSWORD);
}

void printDistance(double distanceRight, double distanceLeft) {
  Serial.print(distanceRight);
  Serial.print(" - ");
  Serial.println(distanceLeft);
}

void sense(int& distanceRight, int& distanceLeft) {
#ifdef LIB_1
  distanceRight = distanceSensorRight.measureDistanceCm();
  distanceLeft = distanceSensorLeft.measureDistanceCm();
#else
  distanceRight = distanceSensorRightBis.read();
  distanceLeft = distanceSensorLeftBis.read();
#endif
}

void doStuff(int distanceRight, int distanceLeft, Motors& myMotors) {
  bool somethingRight = distanceRight > 1 && distanceRight < MIN_DISTANCE;
  bool somethingLeft = distanceLeft > 1 && distanceLeft < MIN_DISTANCE;

  if (somethingRight && somethingLeft)
  {
    Serial.println("Detection Front");
    myMotors.back();
  }
  else if (somethingRight)
  {
    Serial.println ("Detection Right");
    myMotors.turnLeft();
  }
  else if (somethingLeft)
  {
    Serial.println ("Detection Left");
    myMotors.turnRight();
  }
  else {
    myMotors.forward();
  }
}

void loop () {
  int distanceRight = 0;
  int distanceLeft = 0;

  sense(distanceRight, distanceLeft);

  printDistance(distanceRight, distanceLeft);

  doStuff(distanceRight, distanceLeft, motors);
  
  delay(500);
}