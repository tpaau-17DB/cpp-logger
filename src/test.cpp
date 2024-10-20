#include <iostream>

#include "Logger.h"

using namespace std;

int main()
{
    cout<<"----------test start----------"<<endl<<endl;

    cout<<"testing log filtering"<<endl;
    
    for (int i = 0; i < 4; i++)
    {
        cout<<endl<<"Verbosity set to "<<i<<endl;
        Logger::SetVerbosity(Logger::LogLevel(i));
        Logger::PrintDebug("debug");
        Logger::PrintLog("info");
        Logger::PrintWarn("warning");
        Logger::PrintErr("error");
    }

    cout<<endl<<"testing again for overrideFiltering set to true"<<endl;
    Logger::SetOverrideFiltering(true);

    for (int i = 0; i < 4; i++)
    {
        cout<<endl<<"Verbosity set to "<<i<<endl;
        Logger::SetVerbosity(Logger::LogLevel(i));
        Logger::PrintDebug("debug");
        Logger::PrintLog("info");
        Logger::PrintWarn("warning");
        Logger::PrintErr("error");
    }

    cout<<endl<<"Now for nocolor enabled: "<<endl;

    Logger::SetOverrideFiltering(false);
    Logger::SetNoColor(true);
    for (int i = 0; i < 4; i++)
    {
        cout<<endl<<"Verbosity set to "<<i<<endl;
        Logger::SetVerbosity(Logger::LogLevel(i));
        Logger::PrintDebug("debug");
        Logger::PrintLog("info");
        Logger::PrintWarn("warning");
        Logger::PrintErr("error");
    }

    cout<<endl<<"Testing printing with datetime"<<endl;
    Logger::SetNoColor(false);
    Logger::SetShowDateTime(true);
    for (int i = 0; i < 4; i++)
    {
        cout<<endl<<"Verbosity set to "<<i<<endl;
        Logger::SetVerbosity(Logger::LogLevel(i));
        Logger::PrintDebug("debug");
        Logger::PrintLog("info");
        Logger::PrintWarn("warning");
        Logger::PrintErr("error");
    }

    cout<<endl<<"----------test end----------"<<endl;
    return 0;
}
