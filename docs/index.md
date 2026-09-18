# API Reference

## Classes

| Name                              | Description |
| --------------------------------- | ----------- |
| [`LoggerOptions`](#loggeroptions) |             |

## Enumerations

---

### LogLevel

```cpp
enum LogLevel
```

The level of the log, the lower the number the higher the severity.

| Value   | Description                                                                                                                                     |
| ------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| `TRACE` | Most verbose log level.                                                                                                                         |
| `DEBUG` | Diagnostic information used for troubleshooting and testing.                                                                                    |
| `INFO`  | Standard informational messages confirming that things are working as expected..                                                                |
| `WARN`  | Indicates an unexpected or abnormal event that does not disrupt current application.                                                            |
| `ERROR` | Used when a specific transaction or functionality fails, but the rest of the application stays running.                                         |
| `PANIC` | It indicates a unexpected failure. Will call `abort()` after logging.                                                                           |
| `FATAL` | The highest and most severe level. It indicates a catastrophic failure that crashes the application. Will call `exit(EXIT_FAILURE)` afterwards. |

---

### LogType

```cpp
enum LogType
```

How log outputs should look, standard or JSON.

| Value          | Description                                             |
| -------------- | ------------------------------------------------------- |
| `STANDARD_FMT` | Standard log format, just printing `[$LEVEL]: $MESSAGE` |
| `JSON_FMT`     | Output logs as JSON, `{"$LEVEL": "$MESSAGE"}`           |

## Functions

---

### InitLogger

```cpp
void InitLogger(struct LoggerOptions options)
```

Initializes the Logger.

#### Parameters

| Parameter | Type                   | Description        |
| --------- | ---------------------- | ------------------ |
| `options` | `struct LoggerOptions` | The LoggerOptions. |

---

### InitLoggerEasy

```cpp
void InitLoggerEasy(enum LogLevel level)
```

Initializes the Logger the easy way — more defaults.

#### Parameters

| Parameter | Type                         | Description                                        |
| --------- | ---------------------------- | -------------------------------------------------- |
| `level`   | enum [`LogLevel`](#loglevel) | The log level from the [LogLevel](#loglevel) enum. |

---

### PrintLoggerConfig

```cpp
void PrintLoggerConfig(void)
```

Pretty prints the current logger config.

---

### Log

```cpp
void Log(enum LogLevel level, const char * message, ...)
```

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

Gets the current log level.

#### Returns

The current log level as an enum value.

---

### LogLevelToString

```cpp
char * LogLevelToString(enum LogLevel level)
```

Converts and returns a log level enum value as a string.

#### Returns

The current log level as an string value.

#### Parameters

| Parameter | Type                         | Description                             |
| --------- | ---------------------------- | --------------------------------------- |
| `level`   | enum [`LogLevel`](#loglevel) | The desired log level as an enum value. |

## LoggerOptions

```cpp
struct LoggerOptions
```

### Public Attributes

| Return                       | Name                              | Description                                              |
| ---------------------------- | --------------------------------- | -------------------------------------------------------- |
| enum [`LogLevel`](#loglevel) | [`log_level`](#log_level)         | level The log level from the [LogLevel](#loglevel) enum. |
| enum [`LogType`](#logtype)   | [`log_type`](#log_type)           | The log type from the [LogType](#logtype) enum.          |
| `bool`                       | [`timestamp`](#timestamp)         | Turn on or off timestamps in logs.                       |
| `bool`                       | [`flush`](#flush)                 | If true, fflush(stderr) will be called.                  |
| `bool`                       | [`newline`](#newline)             | If true, a newline will be inserted.                     |
| `bool`                       | [`color`](#color)                 | If true, color output will be enabled.                   |
| `bool`                       | [`display_level`](#display_level) | If true, the log level will be logged.                   |

---

#### log_level

```cpp
enum LogLevel log_level
```

Type: enum [`LogLevel`](#loglevel)

level The log level from the [LogLevel](#loglevel) enum.

---

#### log_type

```cpp
enum LogType log_type
```

Type: enum [`LogType`](#logtype)

The log type from the [LogType](#logtype) enum.

---

#### timestamp

```cpp
bool timestamp
```

Turn on or off timestamps in logs.

---

#### flush

```cpp
bool flush
```

If true, fflush(stderr) will be called.

---

#### newline

```cpp
bool newline
```

If true, a newline will be inserted.

---

#### color

```cpp
bool color
```

If true, color output will be enabled.

---

#### display_level

```cpp
bool display_level
```

If true, the log level will be logged.
