#include "SerialLogger.h"

#include <Arduino.h>

SerialLogger::SerialLogger()
{    
  Serial.begin(9600);
}

void SerialLogger::log(int message)
{
  Serial.print(message);
}

void SerialLogger::log(const char* message)
{
  Serial.print(message);
}

