#include <iostream>
#include <string>
#include <iostream>

#include "../src/Logger.h"

using namespace std;

int main()
{
    Logger::SetShowDatetime(false);

    cout<<"----------test start----------\n\n";

    cout<<"testing log filtering\n";
    
    for (int i = 0; i < 4; i++)
    {
        cout<<"\nVerbosity set to " + to_string(i) + "\n";
        Logger::SetVerbosity(Logger::LogLevel(i));
        Logger::PrintDebug("debug");
        Logger::PrintLog("info");
        Logger::PrintWarn("warning");
        Logger::PrintErr("error");
        Logger::ReleaseLogBuffer();
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
        Logger::ReleaseLogBuffer();
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
        Logger::ReleaseLogBuffer();
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
        Logger::ReleaseLogBuffer();
    }

    cout<<"\n---------test end----------\n";
    return 0;
}
