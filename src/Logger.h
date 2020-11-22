#ifndef LOGGER_H
#define LOGGER_H

class Logger {
public:
  virtual void log(int message) = 0;
  virtual void log(const char* message) = 0;
};

class DummyLogger : public Logger {
public:
  void log(int message) override {}
  void log(const char* message) override {}
};

#endif // LOGGER_H
