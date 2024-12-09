#include <iostream>
#include <string>
#include <iostream>

#include "../src/Logger.h"

using namespace std;

int main()
{
    cout<<"----------test start----------"<<endl<<endl;

    Logger::SetLogFilePath("~/gitrepos/cpp-logger/test/output.log");
    

    cout<<endl<<"----------test end----------"<<endl;
    return 0;
}
