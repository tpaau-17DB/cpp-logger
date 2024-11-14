#include <iostream>
#include <string>
#include <iostream>

#include "Logger.h"

using namespace std;

bool logAccumulating = true;

int main()
{
    Logger::SetShowDatetime(true);

    Logger::ClearLogBufer();
    Logger::SetUseLogAccumulation(logAccumulating);

    cout<<"----------test start----------"<<endl<<endl;

    cout<<"testing log filtering\n";
    
    for (int i = 0; i < 4; i++)
    {
        cout<<"\nVerbosity set to " + to_string(i) + "\n";
        Logger::SetVerbosity(Logger::LogLevel(i));
        Logger::PrintDebug("debug");
        Logger::PrintLog("info");
        Logger::PrintWarn("warning");
        Logger::PrintErr("error");
    }

    cout<<"\ntesting again for overrideFiltering set to true\n";
    Logger::SetOverrideFiltering(true);

    for (int i = 0; i < 4; i++)
    {
        cout<<"\nVerbosity set to " + to_string(i) + "\n";
        Logger::SetVerbosity(Logger::LogLevel(i));
        Logger::PrintDebug("debug");
        Logger::PrintLog("info");
        Logger::PrintWarn("warning");
        Logger::PrintErr("error");
    }

    cout<<"\nNow for nocolor enabled: \n";

    Logger::SetOverrideFiltering(false);
    Logger::SetNoColor(true);
    for (int i = 0; i < 4; i++)
    {
        cout<<"\nVerbosity set to " + to_string(i) + "\n";
        Logger::SetVerbosity(Logger::LogLevel(i));
        Logger::PrintDebug("debug");
        Logger::PrintLog("info");
        Logger::PrintWarn("warning");
        Logger::PrintErr("error");
    }

    cout<<"\nTesting printing with datetime\n";
    Logger::SetNoColor(false);
    Logger::SetShowDatetime(true);
    for (int i = 0; i < 4; i++)
    {
        cout<<"\nVerbosity set to " + to_string(i) + "\n";
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
