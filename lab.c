#include <stdlib.h>
#include <stdio.h>

#include <standardloop/logger.h>
// #include "logger.h"

int main(void)
{
    InitLoggerEasy(StringToLogLevel("TRACE"));
    // SetLogLevel(StringToLogLevel("TRACE"));
    Log(TRACE, "hello %s", "world");
    // printf("%s\n", LogLevelToString(GetLogLevel()));
    return EXIT_SUCCESS;
}
