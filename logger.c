#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <time.h>

#include "logger.h"

static Logger logger = {FATAL, JSON_FMT, true, false, true, false};

// log colors - START
enum logColor
{
    LC_RESET = 0,
    LC_CYAN = 1,
    LC_BLUE = 2,
    LC_GREEN = 3,
    LC_YELLOW = 4,
    LC_RED = 5,
    LC_MAGENTA = 6,
};

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

enum logColor logLevelToColor(enum LogLevel);

char *logColorToANSICode(enum logColor);

// log colors - END

void InitLogger(enum LogLevel level, enum LogType type, bool timestamp, bool flush, bool newline, bool color)
{
    SetLogLevel(level);
    logger.log_type = type;
    logger.timestamp = timestamp;
    logger.flush = flush;
    logger.newline = newline;
    logger.color = color;
}

void InitLoggerEasy(enum LogLevel level)
{
    InitLogger(level, JSON_FMT, true, false, true, false);
}

enum LogLevel StringToLogLevel(const char *input_str)
{
    if (strcmp(input_str, "TRACE") == 0)
    {
        return TRACE;
    }
    else if (strcmp(input_str, "DEBUG") == 0)
    {
        return DEBUG;
    }
    else if (strcmp(input_str, "INFO") == 0)
    {
        return INFO;
    }
    else if (strcmp(input_str, "WARN") == 0)
    {
        return WARN;
    }
    else if (strcmp(input_str, "ERROR") == 0)
    {
        return ERROR;
    }
    else if (strcmp(input_str, "FATAL") == 0)
    {
        return FATAL;
    }
    Log(ERROR, "cannot parse log level, will default to TRACE");
    return TRACE;
}

void SetLogLevel(enum LogLevel level)
{
    logger.log_level = level;
}

enum LogLevel GetLogLevel()
{
    return logger.log_level;
}

enum logColor logLevelToColor(enum LogLevel level)
{
    switch (level)
    {
    case FATAL:
        return LC_RED;
    case ERROR:
        return LC_MAGENTA;
    case WARN:
        return LC_YELLOW;
    case DEBUG:
        return LC_GREEN;
    case INFO:
        return LC_BLUE;
    case TRACE:
        return LC_CYAN;
    default:
        return LC_CYAN;
    }
}

char *logColorToANSICode(enum logColor color)
{
    switch (color)
    {
    // case LC_RESET:
    case LC_CYAN:
        return ANSI_COLOR_CYAN;
    case LC_BLUE:
        return ANSI_COLOR_BLUE;
    case LC_GREEN:
        return ANSI_COLOR_GREEN;
    case LC_YELLOW:
        return ANSI_COLOR_YELLOW;
    case LC_RED:
        return ANSI_COLOR_RED;
    case LC_MAGENTA:
        return ANSI_COLOR_MAGENTA;
    default:
        return ANSI_COLOR_CYAN;
    }
}

char *LogLevelToString(enum LogLevel level)
{
    switch (level)
    {
    case FATAL:
        return "FATAL";
    case ERROR:
        return "ERROR";
    case WARN:
        return "WARN";
    case DEBUG:
        return "DEBUG";
    case INFO:
        return "INFO";
    case TRACE:
        return "TRACE";
    default:
        return NULL;
    }
    return NULL;
}

void Log(enum LogLevel level, const char *message, ...)
{
    // FIXMELog configuration
    // char buff[1024];
    // memset(buff, '\0', sizeof(buff));
    // setvbuf(stdout, buff, _IOFBF, 1024);

    if (level > logger.log_level)
    {
        return;
    }

    const char *ll_string = LogLevelToString(level);

    if (logger.color)
    {
        fprintf(stderr, "%s", logColorToANSICode(logLevelToColor(level)));
    }

    // print log level
    if (logger.log_type == STANDARD_FMT)
    {
        fprintf(stderr, "[%s] ", ll_string);
    }
    else if (logger.log_type == JSON_FMT)
    {
        fprintf(stderr, "{\"level\": \"%s\", ", ll_string);
    }

    // print timestamp
    if (logger.timestamp)
    {
        time_t rawtime;
        struct tm *time_info;
        char timestamp[80];

        time(&rawtime);
        time_info = localtime(&rawtime);
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", time_info);
        if (logger.log_type == STANDARD_FMT)
        {
            fprintf(stderr, "[%s]", timestamp);
        }
        else if (logger.log_type == JSON_FMT)
        {
            fprintf(stderr, "\"timestamp\": \"%s\", ", timestamp);
        }
    }

    // print message
    {
        if (logger.log_type == JSON_FMT)
        {
            fprintf(stderr, "\"message\": \"");
        }
        va_list args;
        va_start(args, message);
        vfprintf(stderr, message, args);
        va_end(args);

        if (logger.log_type == JSON_FMT)
        {
            fprintf(stderr, "\"}");
        }
    }

    // print newline
    if (logger.newline)
    {
        fprintf(stderr, "\n");
    }

    if (logger.color)
    {
        fprintf(stderr, "%s", ANSI_COLOR_RESET);
    }

    // flush, TODO research buffer
    if (logger.flush)
    {
        fflush(stderr);
    }

    // FATAL will crash the program on purpose
    if (level == FATAL)
    {
        exit(EXIT_FAILURE);
    }
}
