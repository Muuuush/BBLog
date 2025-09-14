#pragma once
#include <iomanip>
#ifndef __BB_LOGER__
#define __BB_LOGER__

#include <chrono>
#include <iostream>
#include <sstream>
#if __cplusplus >= 202002L // C++20
#include <format>
#endif

namespace bb
{

using namespace std;
using namespace std::chrono;

enum class ELevel
{
    TRACE,
    DEBUG,
    LOG,
    WARN,
    ERROR,
    FATAL,
    NONE
};
inline constexpr const char* LEVEL_LABEL[] = {
    "TRACE",
    "DEBUG",
    "LOG",
    "WARN",
    "ERROR",
    "FATAL",
};
inline constexpr const char* COLOR_LEVEL_LABEL[] = {
    "\e[02;40mTRACE\e[00m",
    "\e[01;34mDEBUG\e[00m",
    "\e[01;40mLOG\e[00m",
    "\e[01;33mWARN\e[00m",
    "\e[01;31mERROR\e[00m",
    "\e[01;41mFATAL\e[00m",
};

// For c++20 or newer stdardard
inline ostream* targetStream = &cout;
// For c++17 or older stdardard
inline FILE* targetFile = stdout;

#if defined(DEBUG) || defined(_DEBUG) || defined(Debug)
inline ELevel level = ELevel::DEBUG;
#else
inline ELevel level = ELevel::LOG;
#endif
inline bool colorBB = true;
inline bool showTime = false;

#if __cplusplus >= 202002L
template <typename... Args>
inline void StdFormatBB(const string_view& label, const string_view& fmt, Args&&... args)
{
    if (showTime)
    {
        (*targetStream) << format("[{}] {:%F %X}: ", label, system_clock::now());
    }
    else
    {
        (*targetStream) << format("[{}]: ", label);
    }
    (*targetStream) << vformat(fmt, make_format_args(forward<Args>(args)...));
    (*targetStream) << endl;
}
template <typename... Args>
inline void StdFormatBB(ELevel level, const string_view& fmt, Args&&... args)
{
    StdFormatBB(LEVEL_LABEL[static_cast<int>(level)], fmt, forward<Args>(args)...);
}
#endif

template <typename... Args>
inline void CFormatBB(const string_view& label, const string_view& fmt, Args&&... args)
{
    if (showTime)
    {
        time_t t = system_clock::to_time_t(system_clock::now());
        tm* tm = localtime(&t);
        stringstream ss;
        ss << "[" << label << "] " << put_time(tm, "%D %X") << ": ";
        fprintf(targetFile, ss.str().c_str());
    }
    else
    {
        fprintf(targetFile, "[%s]: ", label.data());
    }
    fprintf(targetFile, fmt.data(), forward<Args>(args)...);
    fprintf(targetFile, "\n");
}
template <typename... Args>
inline void CFormatBB(ELevel level, const string_view& fmt, Args&&... args)
{
    CFormatBB(LEVEL_LABEL[static_cast<int>(level)], fmt, forward<Args>(args)...);
}

// Use C style while using c++17 or older stdardard;
// Use std::format style while using c++20 or newer stdardard.
template <typename... Args>
inline void BB(const string_view& label, const string_view& fmt, Args&&... args)
{
#if __cplusplus >= 202002L
    StdFormatBB(label, fmt, forward<Args>(args)...);
#else
    CFormatBB(label, fmt, forward<Args>(args)...);
#endif
}

// Use C style while using c++17 or older stdardard;
// Use std::format style while using c++20 or newer stdardard.
template <typename... Args>
inline void BB(ELevel level, const string_view& fmt, Args&&... args)
{
    if (level < bb::level) return;
#if __cplusplus >= 202002L
    if (colorBB)
        StdFormatBB(COLOR_LEVEL_LABEL[static_cast<int>(level)], fmt, forward<Args>(args)...);
    else
        StdFormatBB(LEVEL_LABEL[static_cast<int>(level)], fmt, forward<Args>(args)...);
#else
    if (colorBB)
        CFormatBB(COLOR_LEVEL_LABEL[static_cast<int>(level)], fmt, forward<Args>(args)...);
    else
        CFormatBB(LEVEL_LABEL[static_cast<int>(level)], fmt, forward<Args>(args)...);
#endif
};

template <typename... Args> inline void trace(const string_view& fmt, Args&&... args) { BB(ELevel::TRACE, fmt, forward<Args>(args)...); }
template <typename... Args> inline void debug(const string_view& fmt, Args&&... args) { BB(ELevel::DEBUG, fmt, forward<Args>(args)...); }
template <typename... Args> inline void log(const string_view& fmt, Args&&... args) { BB(ELevel::LOG, fmt, forward<Args>(args)...); }
template <typename... Args> inline void warn(const string_view& fmt, Args&&... args) { BB(ELevel::WARN, fmt, forward<Args>(args)...); }
template <typename... Args> inline void error(const string_view& fmt, Args&&... args) { BB(ELevel::ERROR, fmt, forward<Args>(args)...); }
template <typename... Args> inline void fatal(const string_view& fmt, Args&&... args) { BB(ELevel::FATAL, fmt, forward<Args>(args)...); }

} // namespace bb

#endif
