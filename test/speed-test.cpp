#include <iostream>
#include "../src/Logger.h"

using namespace std;

int main()
{
    cout<<"\n----------test start----------\n";

    Logger::SetUseLogAccumulation(true);
    Logger::SetVerbosity(0);

    for (int i = 0; i < 100000; i++)
    {
        Logger::PrintDebug("debug");
    }

    Logger::ReleaseLogBuffer();

    cout<<"\n----------test end----------\n";
}
