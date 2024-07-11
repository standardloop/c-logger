#ifndef STANDARDLOOP_LOGGER_H
#define STANDARDLOOP_LOGGER_H

enum LogLevel
{
    TRACE = 5,
    DEBUG = 4,
    INFO = 3,
    WARN = 2,
    ERROR = 1,
    FATAL = 0,
};

void Log(enum LogLevel, char *);
void SetLogLevel(enum LogLevel);
enum LogLevel StringToLogLevel(const char *);

enum LogLevel GetLogLevel();
char *LogLevelToString(enum LogLevel);

#endif
