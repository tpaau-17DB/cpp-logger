## cpp-logger
C++ program to filter and print logs

git repo: https://github.com/tpaau-17DB/cpp-logger

## Installing
First clone the repo with `git clone` and navigate to cloned repo with `cd`.

To use the package in your own project simply copy the source files to your project:
```
cp src/Logger.h src/logger.cpp /path/to/project/source
```

## Documentation

<details>

<summary>Printing logs</summary>

Use one of these methods to print logs:
* `Logger::PrintDebug`
* `Logger::PrintLog`
* `Logger::PrintWarn`
* `Logger::PrintErr`

Note that debug logs will get filtered out by default.

</details>


<details>

<summary>Filtering logs</summary>

# By verbosity

Verbosity controls which logs are suppressed and which are not.
Method `Logger::SetVerbosity(...)` is used to set the verbosity value.

Possible verbosity values are:

* [0] All - Don't suppress any logs
* [1] Standard - Only suppress debug logs (default value)
* [2] Quiet - Only show warnings and errors
* [3] ErrorsOnly - This is pretty self-explanatory

You can either use `Logger::LogLevel` enum or an int value to set verbosity to desired level.
Just make sure that verbosity value is in the range of 0-3 or you will get an error.

# Overriding log filtering

Log filtering can be disabled globally by calling `Logger::SetOverrideFiltering(bool)`.

You can disable filtering per-log by passing `overridePriority` set to `true` to any of the logging functions.

</details>


<details>

<summary>Using COLORS!</summary>

Colored logs are enabled by default.
Colors may not be supported by your terminal emulator, conflict with some features or just simply not fit your taste.
`Logger::SetNoColor(bool)` can be used to toggle color.

</details>


<details>

<summary>Enabling log buffering/accumulating</summary>

* Without buffering: Every log message is immediately written to the terminal, which can be a relatively slow operation.
* With buffering: The log messages are stored in memory (RAM) for a period of time. Instead of writing to the terminal or file immediately, logs are stored in buffer and released when `Logger::ReleaseLogBuffer()` is called. This can lead to a significant performance boost.

To toggle log buffering use `Logger::SetUseLogAccumulating(bool)`.

Log buffer can be cleared completely using `Logger::ClearLogBuffer()`.

When log accumulating is enabled logs need to be "released" manually by calling `Logger::ReleaseLogBuffer()` to make them appear in the terminal.

Please make sure to clear the log buffer after releasing it; it doesn't happen automatically!

</details>


<details>

<summary>ncurses mode</summary>

Using `ncurses` mode serves as a workaround to enable logs to be displayed directly in the terminal, even while `ncurses` is running.

Method `Logger::SetNCursesMode(bool)` is used to toggle `ncurses` mode.

When `ncurses` mode is enabled `endwin()` is called before the log is printed.

</details>


<details>

<summary>Displaying datetime</summary>

The Display Dates feature adds a timestamp to each log entry.
You can toggle showing dates with `Logger::SetShowDatetime(bool)` function.

When this is enabled logs will appear like this:
```
[DEB] [14:21:24] debug
[LOG] [14:21:24] info
[WAR] [14:21:24] warning
[ERR] [14:21:24] error
```

You can customize datetime fromat with `Logger::SetDatetimeFromat(string)`.

</details>
