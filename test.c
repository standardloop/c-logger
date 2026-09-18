#include <stdio.h>
#include <stdlib.h>

// #include <standardloop/logger.h>
#include "logger.h"

int main(void)
{

    struct LoggerOptions options = {.log_level = TRACE,
                                    .log_type = STANDARD_FMT,
                                    .timestamp = true,
                                    .flush = true,
                                    .newline = true,
                                    .color = true,
                                    .display_level = true};
    InitLogger(options);
    PrintLoggerConfig();

    Log(TRACE, "testing");

    struct LoggerOptions options_again = {.log_level = TRACE,
                                          .log_type = JSON_FMT,
                                          .timestamp = false,
                                          .flush = true,
                                          .newline = true,
                                          .color = true,
                                          .display_level = false};
    InitLogger(options_again);
    Log(TRACE, "testing");

    return EXIT_SUCCESS;
}
