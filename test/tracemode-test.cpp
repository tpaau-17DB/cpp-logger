#include <iostream>
#include <iostream>

#include "../src/Logger.h"

using namespace std;

int main()
{
    Logger::SetShowDatetime(false);

    cout<<"----------test start----------\n\n";

    cout<<"Testing trace mode\n\n";

    Logger::SetTraceMode(true);

    cout<<"debug log:\n";
    Logger::PrintDebug("debug");
    cout<<"standard log:\n";
    Logger::PrintLog("log");
    cout<<"warning:\n";
    Logger::PrintWarn("warning");
    cout<<"standard error:\n";
    Logger::PrintErr("error");
    cout<<"critical error:\n";
    Logger::PrintCrit("critical");

    cout<<"\n---------test end----------\n";
    return 0;
}
