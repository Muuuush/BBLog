#include "BB_Loger.hpp"
#include <string>

using namespace bb;

int main()
{
    const std::string str = "test format";
    for (int i = (int)ELevel::TRACE; i <= (int)ELevel::NONE; i++)
    {
        level = static_cast<ELevel>(i);
        trace("{}", str);
        debug("{}", str);
        log("{}", str);
        warn("{}", str);
        error("{}", str);
        fatal("{}", str);
    }
    bb::showTime = true;
    colorBB = false;
    for (int i = (int)ELevel::TRACE; i <= (int)ELevel::NONE; i++)
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
