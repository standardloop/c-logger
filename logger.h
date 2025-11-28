#ifndef STANDARDLOOP_LOGGER_H
#define STANDARDLOOP_LOGGER_H

#define STANDARDLOOP_LOGGER_H_MAJOR_VERSION 0
#define STANDARDLOOP_LOGGER_H_MINOR_VERSION 0
#define STANDARDLOOP_LOGGER_H_PATCH_VERSION 1
#define STANDARDLOOP_LOGGER_H_VERSION "0.0.1"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <time.h>

enum LogLevel
{
    TRACE = 5,
    DEBUG = 4,
    INFO = 3,
    WARN = 2,
    ERROR = 1,
    FATAL = 0,
};

enum LogType
{
    JSON = 0,
};

typedef struct Logger
{
    enum LogLevel log_level;
    enum LogType log_type;
    bool timestamp;
    bool flush;
} Logger;

void InitLogger(enum LogLevel level, enum LogType type, bool timestamp, bool flush);
void InitLoggerEasy(enum LogLevel);

void Log(enum LogLevel, const char *, ...);
void SetLogLevel(enum LogLevel);
enum LogLevel StringToLogLevel(const char *);

enum LogLevel GetLogLevel();
char *LogLevelToString(enum LogLevel);

#endif
