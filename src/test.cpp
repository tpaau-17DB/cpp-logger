#include <cmath>
#include <iostream>
#include <string>

#include "Logger.h"

using namespace std;

bool logAccumulating = true;

void addLog(const string& log)
{
    if (logAccumulating)
        Logger::WriteToBuffer(log);
    else
        cout<<log;
}

int main()
{
    Logger::ClearLogBufer();
    Logger::SetUseLogAccumulation(logAccumulating);

    cout<<"----------test start----------"<<endl<<endl;

    addLog("testing log filtering\n");
    
    for (int i = 0; i < 4; i++)
    {
        addLog("\nVerbosity set to " + to_string(i) + "\n");
        Logger::SetVerbosity(Logger::LogLevel(i));
        Logger::PrintDebug("debug");
        Logger::PrintLog("info");
        Logger::PrintWarn("warning");
        Logger::PrintErr("error");
    }

    addLog("\ntesting again for overrideFiltering set to true\n");
    Logger::SetOverrideFiltering(true);

    for (int i = 0; i < 4; i++)
    {
        addLog("\nVerbosity set to " + to_string(i) + "\n");
        Logger::SetVerbosity(Logger::LogLevel(i));
        Logger::PrintDebug("debug");
        Logger::PrintLog("info");
        Logger::PrintWarn("warning");
        Logger::PrintErr("error");
    }

    addLog("\nNow for nocolor enabled: \n");

    Logger::SetOverrideFiltering(false);
    Logger::SetNoColor(true);
    for (int i = 0; i < 4; i++)
    {
        addLog("\nVerbosity set to " + to_string(i) + "\n");
        Logger::SetVerbosity(Logger::LogLevel(i));
        Logger::PrintDebug("debug");
        Logger::PrintLog("info");
        Logger::PrintWarn("warning");
        Logger::PrintErr("error");
    }

    addLog("\nTesting printing with datetime\n");
    Logger::SetNoColor(false);
    Logger::SetShowDateTime(true);
    for (int i = 0; i < 4; i++)
    {
        addLog("\nVerbosity set to " + to_string(i) + "\n");
        Logger::SetVerbosity(Logger::LogLevel(i));
        Logger::PrintDebug("debug");
        Logger::PrintLog("info");
        Logger::PrintWarn("warning");
        Logger::PrintErr("error");
    }

    Logger::ReleaseLogBuffer();

    cout<<endl<<"----------test end----------"<<endl;
    return 0;
}
