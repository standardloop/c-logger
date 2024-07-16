#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "logger.h"

static enum LogLevel log_level = FATAL;

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
    log_level = level;
}

enum LogLevel GetLogLevel()
{
    return log_level;
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

void Log(enum LogLevel level, char *message)
{
    // FIXMELog configuration
    // char buff[1024];
    // memset(buff, '\0', sizeof(buff));
    // setvbuf(stdout, buff, _IOFBF, 1024);

    // FIXMEhave time as well
    // (int)time(NULL);
    // FIXMEallow configuration such as JSON logs etc
    if (level > log_level)
    {
        return;
    }
    switch (level)
    {
    case FATAL:
        if (message == NULL)
        {
            printf("{\"level\": \"FATAL\", \"message\": \"crash on purpose\"}\n");
        }
        else
        {
            printf("{\"level\": \"FATAL\", \"message\": \"%s\"}\n", message);
        }
        exit(EXIT_FAILURE);
    case ERROR:
        printf("{\"level\": \"ERROR\", \"message\": \"%s\"}\n", message);
        break;
    case WARN:
        printf("{\"level\": \"WARN\", \"message\": \"%s\"}\n", message);
        break;
    case DEBUG:
        printf("{\"level\": \"DEBUG\", \"message\": \"%s\"}\n", message);
        break;
    case INFO:
        printf("{\"level\": \"INFO\", \"message\": \"%s\"}\n", message);
        break;
    case TRACE:
        printf("{\"level\": \"TRACE\", \"message\": \"%s\"}\n", message);
        break;
    }
    if (true)
    {
        // temporary
        fflush(stdout);
    }
}
