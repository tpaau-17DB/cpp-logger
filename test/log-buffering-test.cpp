#include <iostream>
#include <string>
#include <iostream>

#include "../src/Logger.h"

using namespace std;

bool logAccumulating = true;

int main()
{
    cout<<"----------test start----------\n\n";

    cout<<"testing log accumulation\n";

    Logger::PrintDebug("debug");
    Logger::PrintLog("info");
    Logger::PrintWarn("warning");
    Logger::PrintErr("error");

    Logger::SetVerbosity(0);
    Logger::SetNoColor(false);

    Logger::ReleaseLogBuffer();

    cout<<"\n----------test end----------\n";
    return 0;
}
