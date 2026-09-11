# API Reference

## Classes

| Name                  | Description                     |
| --------------------- | ------------------------------- |
| [`Logger`](#logger-1) | The [Logger](#logger-1) Struct. |

## Macros

---

### STANDARDLOOP_LOGGER_H_MAJOR_VERSION

```cpp
#define STANDARDLOOP_LOGGER_H_MAJOR_VERSION 0
```

Defined in logger.h:12

Major version of this library.

---

### STANDARDLOOP_LOGGER_H_MINOR_VERSION

```cpp
#define STANDARDLOOP_LOGGER_H_MINOR_VERSION 0
```

Defined in logger.h:16

Minor version of this library.

---

### STANDARDLOOP_LOGGER_H_PATCH_VERSION

```cpp
#define STANDARDLOOP_LOGGER_H_PATCH_VERSION 17
```

Defined in logger.h:20

Patch version of this library.

---

### STANDARDLOOP_LOGGER_H_VERSION

```cpp
#define STANDARDLOOP_LOGGER_H_VERSION "0.0.17"
```

Defined in logger.h:24

Version of this library as a string.

## Enumerations

---

### LogLevel

```cpp
enum LogLevel
```

Defined in logger.h:36

The level of the log, the lower the number the higher the severity.

| Value   | Description |
| ------- | ----------- |
| `TRACE` |             |
| `DEBUG` |             |
| `INFO`  |             |
| `WARN`  |             |
| `ERROR` |             |
| `FATAL` |             |

---

### LogType

```cpp
enum LogType
```

Defined in logger.h:49

How log outputs should look, standard or JSON.

| Value          | Description |
| -------------- | ----------- |
| `STANDARD_FMT` |             |
| `JSON_FMT`     |             |

## Typedefs

---

### Logger

```cpp
using Logger = struct Logger
```

Defined in logger.h:72

The [Logger](#logger-1) Struct.

## Functions

---

### InitLogger

```cpp
void InitLogger(enum LogLevel level, enum LogType type, bool timestamp, bool flush, bool newline, bool color)
```

Defined in logger.h:83

Initializes the [Logger](#logger-1).

#### Parameters

| Parameter   | Type                         | Description                                        |
| ----------- | ---------------------------- | -------------------------------------------------- |
| `level`     | enum [`LogLevel`](#loglevel) | The log level from the [LogLevel](#loglevel) enum. |
| `type`      | enum [`LogType`](#logtype)   | The log type from the [LogType](#logtype) enum.    |
| `timestamp` | `bool`                       | Turn on or off timestamps in logs.                 |
| `flush`     | `bool`                       | If true, fflush(stderr) will be called.            |
| `newline`   | `bool`                       | If true, a newline will be inserted.               |
| `color`     | `bool`                       | If true, color output will be enabled.             |

---

### InitLoggerEasy

```cpp
void InitLoggerEasy(enum LogLevel level)
```

Defined in logger.h:90

Initializes the [Logger](#logger-1) the easy way — more defaults.

#### Parameters

| Parameter | Type                         | Description                                        |
| --------- | ---------------------------- | -------------------------------------------------- |
| `level`   | enum [`LogLevel`](#loglevel) | The log level from the [LogLevel](#loglevel) enum. |

---

### PrintLoggerConfig

```cpp
void PrintLoggerConfig(void)
```

Defined in logger.h:95

Pretty prints the current logger config.

---

### Log

```cpp
void Log(enum LogLevel level, const char * message, ...)
```

Defined in logger.h:103

The most important function of this library - Logs a message.

#### Parameters

| Parameter | Type                         | Description                |
| --------- | ---------------------------- | -------------------------- |
| `level`   | enum [`LogLevel`](#loglevel) | The log level.             |
| `message` | `const char *`               | The message itself to log. |

---

### Panic

```cpp
void Panic(const char * message, ...)
```

Defined in logger.h:110

Similiar to Log but has a custom level and runs abort() at the end.

#### Parameters

| Parameter | Type           | Description                |
| --------- | -------------- | -------------------------- |
| `message` | `const char *` | The message itself to log. |

---

### SetLogLevel

```cpp
void SetLogLevel(enum LogLevel level)
```

Defined in logger.h:116

Sets the log level for the logger.

#### Parameters

| Parameter | Type                         | Description           |
| --------- | ---------------------------- | --------------------- |
| `level`   | enum [`LogLevel`](#loglevel) | What level to set to. |

---

### StringToLogLevel

```cpp
enum LogLevel StringToLogLevel(const char * input_str)
```

Defined in logger.h:123

Sets the log level for the logger.

#### Returns

The log level as an enum value.

#### Parameters

| Parameter   | Type           | Description                        |
| ----------- | -------------- | ---------------------------------- |
| `input_str` | `const char *` | The desired log level as a string. |

---

### GetLogLevel

```cpp
enum LogLevel GetLogLevel()
```

Defined in logger.h:129

Gets the current log level.

#### Returns

The current log level as an enum value.

---

### LogLevelToString

```cpp
char * LogLevelToString(enum LogLevel level)
```

Defined in logger.h:136

Converts and returns a log level enum value as a string.

#### Returns

The current log level as an string value.

#### Parameters

| Parameter | Type                         | Description                             |
| --------- | ---------------------------- | --------------------------------------- |
| `level`   | enum [`LogLevel`](#loglevel) | The desired log level as an enum value. |

## Logger

```cpp
#include <logger.h>
```

```cpp
struct Logger
```

Defined in logger.h:58

The [Logger](#logger-1) Struct.

### Public Attributes

| Return                       | Name                      | Description                                    |
| ---------------------------- | ------------------------- | ---------------------------------------------- |
| enum [`LogLevel`](#loglevel) | [`log_level`](#log_level) | The log level.                                 |
| enum [`LogType`](#logtype)   | [`log_type`](#log_type)   | The log type.                                  |
| `bool`                       | [`timestamp`](#timestamp) | Should the logger output timestamps.           |
| `bool`                       | [`flush`](#flush)         | Should the logger call flush after outputting. |
| `bool`                       | [`newline`](#newline)     | Should the logger add a newline to messages.   |
| `bool`                       | [`color`](#color)         | Should the logger output in color.             |

---

#### log_level

```cpp
enum LogLevel log_level
```

Type: enum [`LogLevel`](#loglevel)

Defined in logger.h:61

The log level.

---

#### log_type

```cpp
enum LogType log_type
```

Type: enum [`LogType`](#logtype)

Defined in logger.h:63

The log type.

---

#### timestamp

```cpp
bool timestamp
```

Defined in logger.h:65

Should the logger output timestamps.

---

#### flush

```cpp
bool flush
```

Defined in logger.h:67

Should the logger call flush after outputting.

---

#### newline

```cpp
bool newline
```

Defined in logger.h:69

Should the logger add a newline to messages.

---

#### color

```cpp
bool color
```

Defined in logger.h:71

Should the logger output in color.

Generated by [Moxygen](https://0state.com/moxygen)
