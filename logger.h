/**
 * @file logger.h
 * @headerfile logger.h <standardloop/logger.h>
 * @brief Small C logger library.
 */

#ifndef STANDARDLOOP_LOGGER_H
#define STANDARDLOOP_LOGGER_H

/**
 * @brief Major version of this library.
 */
#define STANDARDLOOP_LOGGER_H_MAJOR_VERSION 0
/**
 * @brief Minor version of this library.
 */
#define STANDARDLOOP_LOGGER_H_MINOR_VERSION 0
/**
 * @brief Patch version of this library.
 */
#define STANDARDLOOP_LOGGER_H_PATCH_VERSION 17
/**
 * @brief Version of this library as a string.
 */
#define STANDARDLOOP_LOGGER_H_VERSION "0.0.17"

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @brief The level of the log, the lower the number the higher the severity.
 */
enum LogLevel
{
    /** Most verbose log level. */
    TRACE = 5,
    /** Diagnostic information used for troubleshooting and testing. */
    DEBUG = 4,
    /** Standard informational messages confirming that things are working as
     * expected.. */
    INFO = 3,
    /** Indicates an unexpected or abnormal event that does not disrupt current
     * application. */
    WARN = 2,
    /** Used when a specific transaction or functionality fails, but the rest of
     * the application stays running. */
    ERROR = 1,
    /** The highest and most severe level. It indicates a catastrophic failure
     * that crashes the application. */
    FATAL = 0,
};

/**
 * @brief How log outputs should look, standard or JSON.
 */
enum LogType
{
    /** Standard log format, just printing `[$LEVEL]: $MESSAGE` */
    STANDARD_FMT = 0,
    /** Output logs as JSON, `{"$LEVEL": "$MESSAGE"}` */
    JSON_FMT = 1
};

/**
 * @brief Initializes the Logger.
 * @param level The log level from the LogLevel enum.
 * @param type The log type from the LogType enum.
 * @param timestamp Turn on or off timestamps in logs.
 * @param flush If true, fflush(stderr) will be called.
 * @param newline If true, a newline will be inserted.
 * @param color If true, color output will be enabled.
 */
extern void InitLogger(enum LogLevel level, enum LogType type, bool timestamp,
                       bool flush, bool newline, bool color);

/**
 * @brief Initializes the Logger the easy way — more defaults.
 * @param level The log level from the LogLevel enum.
 */
extern void InitLoggerEasy(enum LogLevel level);

/**
 * @brief Pretty prints the current logger config
 */
extern void PrintLoggerConfig(void);

/**
 * @brief The most important function of this library - Logs a message.
 * @param level The log level.
 * @param message The message itself to log.
 * @param ... Extra args for format specification.
 */
extern void Log(enum LogLevel level, const char *message, ...);

/**
 * @brief Similiar to Log but has a custom level and runs abort() at the end.
 * @param message The message itself to log.
 * @param ... Extra args for format specification.
 */
extern void Panic(const char *message, ...);

/**
 * @brief Sets the log level for the logger.
 * @param level What level to set to.
 */
extern void SetLogLevel(enum LogLevel level);

/**
 * @brief Sets the log level for the logger.
 * @param input_str The desired log level as a string.
 * @return The log level as an enum value.
 */
extern enum LogLevel StringToLogLevel(const char *input_str);

/**
 * @brief Gets the current log level.
 * @return The current log level as an enum value.
 */
extern enum LogLevel GetLogLevel();

/**
 * @brief Converts and returns a log level enum value as a string.
 * @param level The desired log level as an enum value.
 * @return The current log level as an string value.
 */
extern char *LogLevelToString(enum LogLevel level);

#endif
