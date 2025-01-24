#include <iostream>
#include <string>
#include <iostream>

#include "../src/Logger.h"

using namespace std;

bool logAccumulating = true;

int main()
{
    cout<<"----------test start----------"<<endl<<endl;

    Logger::ClearLogBufer();
    Logger::SetUseLogAccumulation(logAccumulating);

    cout<<"testing log accumulation\n";

    Logger::PrintDebug("debug");
    Logger::PrintLog("info");
    Logger::PrintWarn("warning");
    Logger::PrintErr("error");

    Logger::SetVerbosity(0);
    Logger::SetNoColor(false);

    Logger::ReleaseLogBuffer();

    cout<<endl<<"----------test end----------"<<endl;
    return 0;
}
