#include <stdlib.h>

#include "./logger.h"

int main(void)
{
    SetLogLevel(StringToLogLevel("TRACE"));
    Log(TRACE, "hello");
    return EXIT_SUCCESS;
}
