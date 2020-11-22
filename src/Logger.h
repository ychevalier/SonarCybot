#ifndef LOGGER_H
#define LOGGER_H

class Logger {
public:
  virtual void log(int message) = 0;
  virtual void log(const char* message) = 0;
};

#endif // LOGGER_H
