#include "BBLog.hpp"
#include <string>

using namespace bb;

int main()
{
    const std::string str = "test format";
    colorBB = false;
    showTime = true;
    cout << setTarget("./target.txt");
    trace("{}", str);
    debug("{}", str);
    log("{}", str);
    warn("{}", str);
    error("{}", str);
    resetTarget();
}
