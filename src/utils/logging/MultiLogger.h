#ifndef MULTILOGGER_H
#define MULTILOGGER_H

#include "utils/Logger.h"

#define MAX_LOGGERS 2

class MultiLogger : public Logger {
public:
  MultiLogger();

  /**
   * @returns true if added, false otherwise (list is already full).
   */
  bool addLogger(Logger* logger);

  void log(int message) override;
  void log(const char* message) override;

private:
  int loggerCount;
  Logger* loggers[MAX_LOGGERS];
};

#endif // MULTILOGGER_H
