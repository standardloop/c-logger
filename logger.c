#include "logger.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
            printf("[FATAL]: crash on purpose\n");
        }
        else
        {
            printf("[FATAL]: %s", message);
        }
        exit(EXIT_FAILURE);
    case ERROR:
        printf("[ERROR]: %s\n", message);
        break;
    case WARN:
        printf("[WARN]: %s\n", message);
        break;
    case DEBUG:
        printf("[DEBUG]: %s\n", message);
        break;
    case INFO:
        printf("[INFO]: %s\n", message);
        break;
    case TRACE:
        printf("[TRACE]: %s\n", message);
        break;
    }
    if (true)
    {
        // temporary
        fflush(stdout);
    }
}
