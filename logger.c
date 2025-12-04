#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <time.h>

#include "logger.h"

static Logger logger = {FATAL, JSON_FMT, true, true};

void InitLogger(enum LogLevel level, enum LogType type, bool timestamp, bool flush)
{
    SetLogLevel(level);
    logger.log_type = type;
    logger.timestamp = timestamp;
    logger.flush = flush;
}

void InitLoggerEasy(enum LogLevel level)
{
    InitLogger(level, JSON_FMT, true, true);
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
    switch (level)
    {
    case FATAL:
        fprintf(stderr, "{\"level\": \"FATAL\", ");
        break;
    case ERROR:
        fprintf(stderr, "{\"level\": \"ERROR\", ");
        break;
    case WARN:
        fprintf(stderr, "{\"level\": \"WARN\", ");
        break;
    case DEBUG:
        fprintf(stderr, "{\"level\": \"DEBUG\", ");
        break;
    case INFO:
        fprintf(stderr, "{\"level\": \"INFO\", ");
        break;
    case TRACE:
        fprintf(stderr, "{\"level\": \"TRACE\", ");
        break;
    }
    if (logger.timestamp)
    {
        time_t rawtime;
        struct tm *time_info;
        char timestamp[80];

        time(&rawtime);
        time_info = localtime(&rawtime);
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", time_info);
        fprintf(stderr, "\"timestamp\": \"%s\", ", timestamp);
    }

    fprintf(stderr, "\"message\": \"");
    va_list args;
    va_start(args, message);
    vfprintf(stderr, message, args);
    va_end(args);
    fprintf(stderr, "\"}\n");

    if (logger.flush)
    {
        fflush(stderr);
    }
    if (level == FATAL)
    {
        exit(EXIT_FAILURE);
    }
}
