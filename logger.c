#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "logger.h"

/**
 * @brief The Logger Struct
 */
typedef struct
{
    struct LoggerOptions options;
} Logger;

static Logger logger = {.options = {.log_level = TRACE,
                                    .log_type = STANDARD_FMT,
                                    .timestamp = true,
                                    .flush = true,
                                    .newline = true,
                                    .color = true,
                                    .display_level = true}};

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

static enum logColor logLevelToColor(enum LogLevel);
static char *logColorToANSICode(enum logColor);
static char *logTypeToString(enum LogType);

// log colors - END

extern void InitLogger(struct LoggerOptions options)
{
    SetLogLevel(options.log_level);
    logger.options.log_type = options.log_type;
    logger.options.timestamp = options.timestamp;
    logger.options.flush = options.flush;
    logger.options.newline = options.newline;
    logger.options.color = options.color;
    logger.options.display_level = options.display_level;
}

extern void InitLoggerEasy(enum LogLevel level)
{
    // all default except for level

    struct LoggerOptions options = {.log_level = level,
                                    .log_type = STANDARD_FMT,
                                    .timestamp = true,
                                    .flush = true,
                                    .newline = true,
                                    .color = true,
                                    .display_level = true};
    InitLogger(options);
}

extern void PrintLoggerConfig(void)
{
    printf("Level: %s\n", LogLevelToString(logger.options.log_level));
    printf("Type: %s\n", logTypeToString(logger.options.log_type));
    printf("Timestamp enabled: %s\n",
           logger.options.timestamp ? "TRUE" : "FALSE");
    printf("Flush enabled: %s\n", logger.options.flush ? "TRUE" : "FALSE");
    printf("Newline enabled: %s\n", logger.options.newline ? "TRUE" : "FALSE");
    printf("Color enabled: %s\n", logger.options.color ? "TRUE" : "FALSE");
    printf("Print Level: %s\n",
           logger.options.display_level ? "TRUE" : "FALSE");
}

static char *logTypeToString(enum LogType type)
{
    switch (type)
    {
    case JSON_FMT:
        return "JSON";
    case STANDARD_FMT:
        return "STANDARD";
    default:
        return "UNKNOWN";
    }
}

extern enum LogLevel StringToLogLevel(const char *input_str)
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
    else if (strcmp(input_str, "PANIC") == 0)
    {
        return PANIC;
    }
    Log(ERROR, "cannot parse log level, will default to TRACE");
    return TRACE;
}

extern void SetLogLevel(enum LogLevel level)
{
    logger.options.log_level = level;
}

extern enum LogLevel GetLogLevel()
{
    return logger.options.log_level;
}

static enum logColor logLevelToColor(enum LogLevel level)
{
    switch (level)
    {
    case PANIC:
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

static char *logColorToANSICode(enum logColor color)
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

extern char *LogLevelToString(enum LogLevel level)
{
    switch (level)
    {
    case PANIC:
        return "PANIC";
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

extern void Log(enum LogLevel level, const char *message, ...)
{
    // FIXMELog configuration
    // char buff[1024];
    // memset(buff, '\0', sizeof(buff));
    // setvbuf(stdout, buff, _IOFBF, 1024);

    if (level > logger.options.log_level)
    {
        return;
    }

    const char *ll_string = LogLevelToString(level);

    if (logger.options.color)
    {
        fprintf(stderr, "%s", logColorToANSICode(logLevelToColor(level)));
    }

    // print log level
    if (logger.options.log_type == STANDARD_FMT)
    {
        if (logger.options.display_level)
        {
            fprintf(stderr, "[%s] ", ll_string);
        }
    }
    else if (logger.options.log_type == JSON_FMT)
    {
        if (logger.options.display_level)
        {
            fprintf(stderr, "{\"level\": \"%s\", ", ll_string);
        }
        else
        {
            fprintf(stderr, "{");
        }
    }

    // print timestamp
    if (logger.options.timestamp)
    {
        time_t rawtime;
        struct tm *time_info;
        char timestamp[80];

        time(&rawtime);
        time_info = localtime(&rawtime);
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", time_info);
        if (logger.options.log_type == STANDARD_FMT)
        {
            fprintf(stderr, "[%s] ", timestamp);
        }
        else if (logger.options.log_type == JSON_FMT)
        {
            fprintf(stderr, "\"timestamp\": \"%s\", ", timestamp);
        }
    }

    if (logger.options.log_type == JSON_FMT)
    {
        fprintf(stderr, "\"message\": \"");
    }
    va_list args;
    va_start(args, message);
    vfprintf(stderr, message, args);
    va_end(args);

    if (logger.options.log_type == JSON_FMT)
    {
        fprintf(stderr, "\"}");
    }

    // print newline
    if (logger.options.newline)
    {
        fprintf(stderr, "\n");
    }

    if (logger.options.color)
    {
        fprintf(stderr, "%s", ANSI_COLOR_RESET);
    }

    // flush, TODO research buffer
    if (logger.options.flush)
    {
        fflush(stderr);
    }

    if (level == PANIC)
    {
        abort();
    }
    else if (level == FATAL)
    {
        exit(EXIT_FAILURE);
    }
}
