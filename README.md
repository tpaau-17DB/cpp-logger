# cpp-logger
A `C++` logger library


# Installing
First clone the repo with `git clone` and navigate to cloned repo with `cd`.

To install the library, run the following script:
```
sudo ./install
```
This will automatically place the headers in `/usr/local/include/pretty-logger/`.

Once installed, include the logger in your project by adding:
```
#include <pretty-logger/Logger.h>
```


# Documentation

<details><summary>Printing logs</summary>

Use one of these methods to print logs:
* `PrintDebug()` - debug logs
* `PrintLog()` - standard, informative logs
* `PrintWarn()` - warnings
* `PrintErr()` - errors
* `PrintCrit()` - fatal errors

Note that debug logs will get filtered out by default.

</details>


<details><summary>Filtering logs</summary>

## By verbosity

Verbosity controls which logs are suppressed and which are not.
Method `SetLoggerVerbosity(...)` is used to set the verbosity value.

Possible verbosity values are:
* `All` - Don't suppress any logs
* `Standard` - Only suppress debug logs (default value)
* `Quiet` - Only show warnings and errors
* `ErrorsOnly` - This is pretty self-explanatory

You can either use `LogLevel` `enum` or an `int` value to set verbosity to
desired level. Just make sure that verbosity value is in the range of `0`-`3`
or you will get an error.


## Overriding log filtering

To toggle log filtering override, call `ToggleLogFilteringOverride(bool)`.
Setting this to true will completely disable log filtering.

Also, you can disable filtering per-log by passing `overridePriority` set to
`true` to any of the logging functions.

</details>


<details><summary>Using colors</summary>

Colored logs are enabled by default. Colors may not be supported by your
terminal, conflict with some features or just simply not fit your taste.
`ToggleLogColor(bool)` can be used to toggle colored logs.

</details>


<details><summary>Custom log streams</summary>

By default, the logger directs all logs to the `clog` stream. However, this is
not fixed, and you can set a custom log stream controlled by you.

You can set the stream pointer using `SetLogOutputStream(ostringstream*)`.
Then, tell the logger you want to use this custom log stream by calling
`UseCustomOutputStream(bool)`.

Custom log buffer can be flushed into `clog` at any time using 
`FlushLogStream()`.

</details>


<details><summary>File logging</summary>

File logging is a feature that allows you to output logs to a file. While this
can be achieved using a custom log stream, using the logger's file logging
feature is much more straightforward. The file log stream is buffered by
default and automatically flushed when it exceeds a specific size
(`128` logs by default).

* The maximum buffer size can be set with `SetMaxFileLogBufferSize(int)`.
* The log file path can be modified with `SetLogFilePath(string&)`.
* To toggle file logging, use `ToggleFileLogging(bool)`.

Remember to always flush file log buffer when the program exits, by calling
`FlushFileLogBuffer()`.

</details>


<details><summary>Displaying datetime</summary>

The datetime feature adds a timestamp to each log entry. You can toggle showing
dates with `ToggleLogDatetime(bool)` function.

When this option enabled logs will appear like so:
```
[DEB] [14:21:24] debug
[LOG] [14:21:24] info
[WARN] [14:21:24] warning
[ERR] [14:21:24] error
[CRIT] [14:21:24] critical
```

You can customize datetime format with `SetLogDatetimeFromat(string)`.

</details>
