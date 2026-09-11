# c-logger

[https://github.com/standardloop/c-logger](https://github.com/standardloop/c-logger)

[![GitHub Release](https://img.shields.io/github/v/release/standardloop/c-logger?sort=semver)](https://github.com/standardloop/c-logger/releases) ![C Version](https://img.shields.io/badge/C_Standard-C17-00599C?logo=c&logoColor=white)

## About

`c-logger` is a small logger dynamic library.

Right now, it is essentially a wrapper around `fprintf`.

I use it for many of my projects.

It supports:

- `JSON` logs or Normal Logs
- Add a date to the log.
- Log levels
  - `TRACE`
  - `DEBUG`
  - `INFO`
  - `WARN`
  - `ERROR`
  - `FATAL`
- Color Output

## Usage

### Example Program

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

## Docs

Docs are generated a first generated with `doxygen` as `xml` and then `moxygen` reads the xml to output markdown in the `docs/` folder.

See the `docs` tasks in the `Taskfile.yml`
