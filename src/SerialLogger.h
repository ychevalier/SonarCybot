#ifndef SERIALLOGGER_H
#define SERIALLOGGER_H

#include "Logger.h"

class SerialLogger : public Logger {
public:
  SerialLogger();

  void log(int message) override;
  void log(const char* message) override;
};

#endif // SERIALLOGGER_H
