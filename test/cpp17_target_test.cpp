#include "BBLog.hpp"
#include <iostream>
#include <string>

using namespace bb;

int main()
{
    const std::string str = "test format";
    colorBB = false;
    showTime = true;
    cout << setTarget("./target.txt");
    trace("%s", str.c_str());
    debug("%s", str.c_str());
    log("%s", str.c_str());
    warn("%s", str.c_str());
    error("%s", str.c_str());
}
