#include <iostream>
#include <string>
#include <iostream>

#include "../src/Logger.h"

using namespace std;

int main()
{
    cout<<"----------test start----------\n\n";

    cout<<"Testing log filtering\n";
    
    for (int i = 0; i < 4; i++)
    {
        cout<<"\nVerbosity set to " + to_string(i) + "\n";
        SetLoggerVerbosity(LogLevel(i));
        PrintDebug("debug");
        PrintLog("info");
        PrintWarn("warning");
        PrintErr("error");
        PrintCrit("critical");
    }

    cout<<"\nTesting for global filtering override\n";

    ToggleLogFilteringOverride(true);
    for (int i = 0; i < 4; i++)
    {
        cout<<"\nVerbosity set to " + to_string(i) + "\n";
        SetLoggerVerbosity(LogLevel(i));
        PrintDebug("debug");
        PrintLog("info");
        PrintWarn("warning");
        PrintErr("error");
        PrintCrit("critical");
    }
    ToggleLogFilteringOverride(false);

    cout<<"\nTesting for local filtering override\n";

    for (int i = 0; i < 4; i++)
    {
        cout<<"\nVerbosity set to " + to_string(i) + "\n";
        SetLoggerVerbosity(LogLevel(i));
        PrintDebug("debug", true);
        PrintLog("info", true);
        PrintWarn("warning", true);
        PrintErr("error", true);
        PrintCrit("critical", true);
    }

    cout<<"\nTesting for nocolor enabled: \n";

    ToggleLogColor(true);
    for (int i = 0; i < 4; i++)
    {
        cout<<"\nVerbosity set to " + to_string(i) + "\n";
        SetLoggerVerbosity(LogLevel(i));
        PrintDebug("debug");
        PrintLog("info");
        PrintWarn("warning");
        PrintErr("error");
        PrintCrit("critical");
    }
    ToggleLogColor(false);

    cout<<"\nTesting printing with datetime\n";

    ToggleLogDatetime(true);
    for (int i = 0; i < 4; i++)
    {
        cout<<"\nVerbosity set to " + to_string(i) + "\n";
        SetLoggerVerbosity(LogLevel(i));
        PrintDebug("debug");
        PrintLog("info");
        PrintWarn("warning");
        PrintErr("error");
        PrintCrit("critical");
    }

    cout<<"\n---------test end----------\n";
    return 0;
}
