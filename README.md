# cpp-logger
C++ program to filter and print logs

git repo: https://github.com/tpaau-17DB/cpp-logger

# Installing
First clone the repo with `git clone` and navigate to cloned repo with `cd`.

To use the package in your own project simply copy the source files to your project:
```
cp src/Logger.h src/logger.cpp /path/to/project/source/
```

# Documentation

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

## By verbosity

Verbosity controls which logs are suppressed and which are not.
Method `Logger::SetVerbosity(...)` is used to set the verbosity value.

Possible verbosity values are:

* [0] All - Don't suppress any logs
* [1] Standard - Only suppress debug logs (default value)
* [2] Quiet - Only show warnings and errors
* [3] ErrorsOnly - This is pretty self-explanatory

You can either use `Logger::LogLevel` `enum` or an `int` value to set verbosity to desired level.
Just make sure that verbosity value is in the range of 0-3 or you will get an error.

## Overriding log filtering

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

<summary>Using log buffering/accumulating</summary>

## Log buffering
Log buffering temporarily stores logs in RAM instead of printing them directly to the terminal.
This approach improves performance by reducing I/O operations.

The log buffer is automatically released when it reaches a limit of 100 logs.
You can also manually release the buffer at any time by calling `Logger::ReleaseLogBuffer()`.

To ensure all logs are printed when the program exits, it’s important to release the buffer explicitly.

Buffering also ensures that log settings (such as log level or format) are consistently applied when the buffer is released, making the log output more consistent.

You can customize the max buffer size using `Logger::SetMaxLogBufferSize(int).`

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

When this option enabled logs will appear like so:
```
[DEB] [14:21:24] debug
[LOG] [14:21:24] info
[WAR] [14:21:24] warning
[ERR] [14:21:24] error
```

You can customize datetime format with `Logger::SetDatetimeFromat(string)`.

</details>
