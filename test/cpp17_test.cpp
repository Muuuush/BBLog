#include "BBLog.hpp"
#include <string>

using namespace bb;

int main()
{
    const std::string str = "test format";
    for (int i = (int)ELevel::TRACE; i <= (int)ELevel::NONE; i++)
    {
        level = static_cast<ELevel>(i);
        trace("%s", str.c_str());
        debug("%s", str.c_str());
        log("%s", str.c_str());
        warn("%s", str.c_str());
        error("%s", str.c_str());
        fatal("%s", str.c_str());
    }
    showTime = true;
    colorBB = false;
    for (int i = (int)ELevel::TRACE; i <= (int)ELevel::NONE; i++)
    {
        level = static_cast<ELevel>(i);
        trace("%s", str.c_str());
        debug("%s", str.c_str());
        log("%s", str.c_str());
        warn("%s", str.c_str());
        error("%s", str.c_str());
        fatal("%s", str.c_str());
    }
}
