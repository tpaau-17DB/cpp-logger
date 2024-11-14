#include <iostream>
#include <string>
#include <iostream>

#include "Logger.h"

using namespace std;

bool logAccumulating = true;

int main()
{
    cout<<"----------test start----------"<<endl<<endl;

    Logger::ClearLogBufer();
    Logger::SetUseLogAccumulation(logAccumulating);

    cout<<"testing log accumulation\n";
    
    for (int i = 0; i < 4; i++)
    {
        cout<<"\nVerbosity set to " + to_string(i) + "\n";
        Logger::SetVerbosity(Logger::LogLevel(i));
        Logger::PrintDebug("debug");
        Logger::PrintLog("info");
        Logger::PrintWarn("warning");
        Logger::PrintErr("error");
    }

    Logger::SetNoColor(true);

    Logger::ReleaseLogBuffer();

    cout<<endl<<"----------test end----------"<<endl;
    return 0;
}
