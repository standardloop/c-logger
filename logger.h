/**
 * @file logger.h
 * @brief Header file
 */

#ifndef STANDARDLOOP_LOGGER_H
#define STANDARDLOOP_LOGGER_H

#define STANDARDLOOP_LOGGER_H_MAJOR_VERSION 0
#define STANDARDLOOP_LOGGER_H_MINOR_VERSION 0
#define STANDARDLOOP_LOGGER_H_PATCH_VERSION 17
#define STANDARDLOOP_LOGGER_H_VERSION "0.0.17"

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

/**
 * @brief Initializes the Logger
 * @param level The log level from the LogLevel enum.
 * @param type The log type from the LogType enum.
 * @param timestamp Turn on or off timestamps in logs.
 * @param flush If true, fflush(stderr) will be called.
 * @param newline If true, a newline will be inserted.
 * @param color If true, color output will be enabled.
 */
extern void InitLogger(enum LogLevel level, enum LogType type, bool timestamp,
                       bool flush, bool newline, bool color);
extern void InitLoggerEasy(enum LogLevel);
extern void PrintLoggerConfig(void);

extern void Log(enum LogLevel, const char *, ...);
extern void Panic(const char *, ...);
extern void SetLogLevel(enum LogLevel);
extern enum LogLevel StringToLogLevel(const char *);

extern enum LogLevel GetLogLevel();
extern char *LogLevelToString(enum LogLevel);

#endif
