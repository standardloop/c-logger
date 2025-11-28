# c-logger

Simple C logging package created from scratch for educational purposes

## Disclaimer

The taskfile is currently only configured for macOS

## Usage

### Setup

```sh
$ task release
```

### Example Program

#### Source
```C
#include <stdlib.h>
#include <stdio.h>

#include <standardloop/logger.h>

int main(void)
{
    InitLoggerEasy(StringToLogLevel("TRACE"));
    Log(TRACE, "hello %s", "world");
    return EXIT_SUCCESS;
}
```
