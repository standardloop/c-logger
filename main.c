#include <stdlib.h>
#include <stdio.h>

#include "./logger.h"

int main(void)
{
    SetLogLevel(StringToLogLevel("TRACE"));
    Log(TRACE, "hello");
    //printf("%s\n", LogLevelToString(GetLogLevel()));
    return EXIT_SUCCESS;
}
