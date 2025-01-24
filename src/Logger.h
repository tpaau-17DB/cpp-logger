#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>
#include <ctime>

// PUBLIC STRUCTS
enum LogLevel
{
    Verbose = 0,
    Standard = 1,
    Quiet = 2,
    ErrorsOnly = 3
};

struct BufferedLog
{
    std::string Message = "E";
    time_t Date;
    short LogLevel = 0;
    bool OverrideFiltering = false;
    bool IsRaw = false;
};

// GETTERS
LogLevel GetVerbosity();


// SETTERS
void SetVerbosity(const LogLevel verbosity);
void SetVerbosity(const int verbosity);

void SetOverrideFiltering(const bool enabled);
void SetNCursesMode(const bool enabled);

void SetNoColor(const bool enabled);

void SetMaxLogBufferSize(const int limit);

void SetShowDatetime(const bool enabled);
void SetDatetimeFormat(const std::string format);

void SetLogFilePath(const std::string& path);
void SetFileLogging(const bool enabled);

void SetTraceMode(const bool enabled);


// PRINTING FUNCTIONS
void PrintDebug(const std::string& message);
void PrintDebug(const std::string& message, const bool overrideFiltering);

void PrintLog(const std::string& message);
void PrintLog(const std::string& message, const bool overrideFiltering);

void PrintWarn(const std::string& message);
void PrintWarn(const std::string& message, const bool overrideFiltering);

void PrintErr(const std::string& message);
void PrintErr(const std::string& message, const bool overrideFiltering); 

void PrintCrit(const std::string& message);
void PrintCrit(const std::string& message, const bool overrideFiltering); 

// OTHER PUBLIC FUNCTIONS
void ReleaseLogBuffer();
void WriteLogToBuffer(const BufferedLog& log);

#endif
