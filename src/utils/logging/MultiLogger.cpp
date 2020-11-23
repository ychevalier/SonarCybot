#include "MultiLogger.h"

MultiLogger::MultiLogger()
: loggerCount(0) {
  for (int i = 0; i < MAX_LOGGERS; ++i) {
    loggers[i] = nullptr;
  }
}

bool MultiLogger::addLogger(Logger* logger) {
  if (loggerCount < MAX_LOGGERS) {
    loggers[loggerCount] = logger;
    ++loggerCount;
    return true;
  }
  return false;
}

void MultiLogger::log(int message)
{
  for (Logger* logger : loggers) {
    if (logger != nullptr) {
      logger->log(message);    
    }
  }
}

void MultiLogger::log(const char* message) {
  for (Logger* logger : loggers) {
    if (logger != nullptr) {
      logger->log(message);    
    }
  }
}



