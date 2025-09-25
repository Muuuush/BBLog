#include "BBLog.hpp"
#include <string>

using namespace bb;

int main()
{
    const std::string str = "test format";
    for (int i = (int)ELevel::E_TRACE; i <= (int)ELevel::E_NONE; i++)
    {
        level = static_cast<ELevel>(i);
        trace("{}", str);
        debug("{}", str);
        log("{}", str);
        warn("{}", str);
        error("{}", str);
        fatal("{}", str);
    }
    target = &cerr;
    bb::showTime = true;
    colorBB = false;
    for (int i = (int)ELevel::E_TRACE; i <= (int)ELevel::E_NONE; i++)
    {
        level = static_cast<ELevel>(i);
        trace("{}", str);
        debug("{}", str);
        log("{}", str);
        warn("{}", str);
        error("{}", str);
        fatal("{}", str);
    }
}
