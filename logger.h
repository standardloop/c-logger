#ifndef STANDARDLOOP_LOGGER_H
#define STANDARDLOOP_LOGGER_H

#define STANDARDLOOP_LOGGER_H_MAJOR_VERSION 0
#define STANDARDLOOP_LOGGER_H_MINOR_VERSION 0
#define STANDARDLOOP_LOGGER_H_PATCH_VERSION 9
#define STANDARDLOOP_LOGGER_H_VERSION "0.0.9"

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
    STANDARD_FMT = 0,
    JSON_FMT = 1
};

typedef struct Logger
{
    enum LogLevel log_level;
    enum LogType log_type;
    bool timestamp;
    bool flush;
    bool newline;
    bool color;
} Logger;

void InitLogger(enum LogLevel, enum LogType, bool, bool, bool, bool);
void InitLoggerEasy(enum LogLevel);

void Log(enum LogLevel, const char *, ...);
void SetLogLevel(enum LogLevel);
enum LogLevel StringToLogLevel(const char *);

enum LogLevel GetLogLevel();
char *LogLevelToString(enum LogLevel);

#endif
