#ifndef STANDARDLOOP_LOGGER_H
#define STANDARDLOOP_LOGGER_H

#define STANDARDLOOP_LOGGER_H_MAJOR_VERSION 0
#define STANDARDLOOP_LOGGER_H_MINOR_VERSION 0
#define STANDARDLOOP_LOGGER_H_PATCH_VERSION 1
#define STANDARDLOOP_LOGGER_H_VERSION "0.0.1"

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
