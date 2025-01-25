# cpp-logger
A `C++` logger library


# Installing
First clone the repo with `git clone` and navigate to cloned repo with `cd`.


To use the library in your own project simply copy the source files to your project:
```
cp src/Logger.h src/logger.cpp /target/
```

Or you can run `install` script that will install sources automatically to
`/usr/local/include/pretty-logger/`.


Then, include the `Logger.h` file in your project to use all its features.


# Documentation

<details>

<summary>Printing logs</summary>

Use one of these methods to print logs:
* `PrintDebug()`
* `PrintLog()`
* `PrintWarn()`
* `PrintErr()`
* `PrintCrit()`

Note that debug logs will get filtered out by default.

</details>


<details>

<summary>Filtering logs</summary>

## By verbosity

Verbosity controls which logs are suppressed and which are not.
Method `SetLoggerVerbosity(...)` is used to set the verbosity value.

Possible verbosity values are:

* [0] All - Don't suppress any logs
* [1] Standard - Only suppress debug logs (default value)
* [2] Quiet - Only show warnings and errors
* [3] ErrorsOnly - This is pretty self-explanatory

You can either use `LogLevel` `enum` or an `int` value to set verbosity to
desired level. Just make sure that verbosity value is in the range of 0-3 or
you will get an error.

## Overriding log filtering

To override log filtering, call `ToggleLogFilteringOverride(bool)`.

You can disable filtering per-log by passing `overridePriority` set to `true`
to any of the logging functions.

</details>


<details>

<summary>Using COLORS!</summary>

Colored logs are enabled by default.
Colors may not be supported by your terminal emulator, conflict with some
features or just simply not fit your taste.
`ToggleLogColor(bool)` can be used to toggle color.

</details>


<details>

<summary>Custom log stream</summary>

By default, the logger directs all logs to the clog stream. However, this is
not fixed, and you can set a custom log buffer controlled by you.


You can set the buffer pointer using `SetLogOutputStream(ostringstream*)`.
Then, tell the logger you want to use this custom log buffer by calling
`ToggleUseCustomOutputStream(bool)`.


Custom log buffer can be flushed into `clog` at any time using 
`FlushLogStream()`.

</details>


<details>

<summary>File logging</summary>

File logging is a feature that allows you to output logs to a file. While this
can be achieved using a custom log stream, using the logger's file logging
feature is much more straightforward. The file log stream is buffered by
default and automatically flushed when it exceeds a specific size
(`128` logs by default).

* The maximum buffer size can be set with `SetMaxFileLogBufferSize(int)`.
* The log file path can be modified with `SetLogFilePath(string&)`.
* To toggle file logging, use `ToggleFileLogging(bool)`.

---

Remember to always flush file log buffer when the program exits using
`FlushFileLogBuffer()`.

</details>


<details>

<summary>Displaying datetime</summary>

The Display Dates feature adds a timestamp to each log entry.
You can toggle showing dates with `ToggleLogDatetime(bool)` function.

When this option enabled logs will appear like so:
```
[DEB] [14:21:24] debug
[LOG] [14:21:24] info
[WAR] [14:21:24] warning
[ERR] [14:21:24] error
```

You can customize datetime format with `SetLogDatetimeFromat(string)`.

</details>
