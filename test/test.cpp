#include <iostream>
#include <string>
#include <iostream>

#include "../src/Logger.h"

using namespace std;

int main()
{
    cout<<"----------test start----------"<<endl<<endl;

    Logger::ToggleLogAccumulation(true);
    Logger::ToggleFileLogging(true);
    Logger::SetLogFilePath("~/gitrepos/cpp-logger/test/output.log");
    
    for (int i = 0; i < 4; i++)
    {
        cout<<"\nVerbosity set to " + to_string(i) + "\n";
        Logger::SetVerbosity(Logger::LogLevel(i));
        Logger::PrintDebug("debug");
        Logger::PrintLog("info");
        Logger::PrintWarn("warning");
        Logger::PrintErr("error");
        Logger::ReleaseLogBuffer();
        Logger::ClearLogBufer();
    }

    cout<<endl<<"----------test end----------"<<endl;
    return 0;
}
