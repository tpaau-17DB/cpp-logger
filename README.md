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
