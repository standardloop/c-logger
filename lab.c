#include <stdlib.h>
#include <stdio.h>

// #include <standardloop/logger.h>
#include "logger.h"

int main(void)
{
    InitLoggerEasy(StringToLogLevel("TRACE"));
    // SetLogLevel(StringToLogLevel("TRACE"));
    Log(TRACE, "hello %s", "world");
    // printf("%s\n", LogLevelToString(GetLogLevel()));

    InitLogger(TRACE, STANDARD_FMT, false, true, true, true);
    Log(TRACE, "hello %s", "world");
    Log(INFO, "hello %s", "world");
    Log(DEBUG, "hello %s", "world");
    Log(WARN, "hello %s", "world");
    Log(ERROR, "hello %s", "world");
    Log(FATAL, "hello %s", "world");
    return EXIT_SUCCESS;
}
