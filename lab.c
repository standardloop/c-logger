#include <stdlib.h>
#include <stdio.h>

#include <standardloop/logger.h>

int main(void)
{
    SetLogLevel(StringToLogLevel("TRACE"));
    Log(TRACE, "hello");
    // printf("%s\n", LogLevelToString(GetLogLevel()));
    return EXIT_SUCCESS;
}
