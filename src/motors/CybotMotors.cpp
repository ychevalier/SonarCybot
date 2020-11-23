#include "CybotMotors.h"

#include <Arduino.h>

CybotMotors::CybotMotors(int rightForwardPin, int rightBackwardPin, int leftForwardPin, int leftBackwardPin)
: rightForwardPin(rightForwardPin)
, rightBackwardPin(rightBackwardPin)
, leftForwardPin(leftForwardPin) 
, leftBackwardPin(leftBackwardPin)  
{    
  pinMode(rightForwardPin, OUTPUT);
  pinMode(rightBackwardPin, OUTPUT);
  pinMode(leftForwardPin, OUTPUT);
  pinMode(leftBackwardPin, OUTPUT);
  
  reset();
}

void CybotMotors::forward() {
  reset();
  digitalWrite(rightForwardPin, HIGH);
  digitalWrite(leftForwardPin, HIGH);
}

void CybotMotors::back() {
  reset();
  digitalWrite(leftBackwardPin, HIGH);
  digitalWrite(rightBackwardPin, HIGH);
  delay(1000);
  reset();
}

void CybotMotors::stop() {
  reset();
}

void CybotMotors::turnRight() {
  reset();
  digitalWrite(leftForwardPin, HIGH);
  digitalWrite(rightBackwardPin, HIGH);
  delay(500);
  reset();
}

void CybotMotors::turnLeft() {
  reset();
  digitalWrite(rightForwardPin, HIGH);
  digitalWrite(leftBackwardPin, HIGH);
  delay(500);
  reset();
}

void CybotMotors::reset() {
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(rightBackwardPin, LOW);
  digitalWrite(leftForwardPin, LOW);
  digitalWrite(leftBackwardPin, LOW);
}