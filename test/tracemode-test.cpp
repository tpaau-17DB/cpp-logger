#include <iostream>
#include <iostream>

#include "../src/Logger.h"

using namespace std;

int main()
{
    cout<<"----------test start----------\n\n";

    cout<<"Testing trace mode\n\n";

    SetTraceMode(true);
    SetVerbosity(Verbose);

    cout<<"debug log:\n";
    PrintDebug("debug");
    cout<<"standard log:\n";
    PrintLog("log");
    cout<<"warning:\n";
    PrintWarn("warning");
    cout<<"standard error:\n";
    PrintErr("error");
    cout<<"critical error:\n";
    PrintCrit("critical");

    cout<<"\n---------test end----------\n";
    return 0;
}
