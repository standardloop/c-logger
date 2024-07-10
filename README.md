# c-logger

Simple C logging package created from scratch for educational purposes

## Usage

### Setup

```sh
$ make release
```

### Example Program

#### Source
```C
#include <standardloop/logger.h>

int main(void)
{
    SetLogLevel(StringToLogLevel("TRACE"));
    Log(TRACE, "hello");
    return 0;
}
```

#### Compile

```sh
$ gcc main.c -L/usr/local/lib/standardloop -lstandardloop-logger
```
