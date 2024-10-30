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

Note that debug logs will be filtered out bu default.


</details>


<details>

<summary>Filtering logs</summary>

# By verbosity

Verbosity controls which logs are getting suppressed and which are not.
Methods `Logger::SetVerbosity(...)` are used to set the verbosity value.

Possible verbosity values are:

* [0] All - Don't suppress any logs
* [1] Standard - Only suppress debug logs (dafault value)
* [2] Quiet - Only show warnings and errors
* [3] ErrorsOnly - It's pretty self-explanatory

You can either use `Logger::LogLevel` enum or an int value to set verbosity to desired level. Just make sure that verbosity value is in range of 0-3 or you will get an error.

# Overriding log filtering

Log filtering can be disabled globally by calling `Logger::SetOverrideFiltering(bool)`.

</details>


<details>

<summary>Using COLORS!</summary>

Colored logs are enabled by default.
Colors may not be supported by your terminal emulator, conflict with some features or just simply not fit your taste.
`Logger::SetNoColor(bool)` can be used to toggle colored logs.

</details>


<details>

<summary>Enabling log buffering/accumulating</summary>

Log buffering is a feature that manages logs more efficiently.
When log buffering is enabled logger stores messages in RAM instead of printing them directly into the terminal. 

To toggle log buffering use `Logger::SetUseLogAccumulating(bool)`.

Log buffer can be cleared completely using `Logger::ClearLogBuffer()`.

You can also write directly to the buffer using `Logger::WriteToBuffer(string&)`.

When log accumulating is enabled logs need to be "released" manually by calling `Logger::ReleaseLogBuffer()` to make them appear in the terminal.
Please make sure to clear the log buffer after releasing it, it does not happen automatically!

</details>
