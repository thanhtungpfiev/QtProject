/**
 * \author tungdt9 thanhtungpfiev@gmail.com
 *
 * \date 12/25/2016
 *
 * \class
 *
 * \brief
 *
 *
 */

#ifndef BOOSTLOGGER_H
#define BOOSTLOGGER_H

/* Enable all log levels by default */
#ifndef _LOG_LEVEL
#define _LOG_LEVEL 6
#endif /* #ifndef _AGD_LOG_LEVEL */

#ifndef BOOST_ALL_DYN_LINK
#define BOOST_ALL_DYN_LINK
#endif /* #ifndef BOOST_ALL_DYN_LINK */

#include <boost/log/trivial.hpp>

#ifndef _NDEBUG
#define _LOG_LOCATION <<__FILE__<<"("<<__LINE__<<")("<<__func__<<") "
#else /* #ifndef _NDEBUG */
#define _LOG_LOCATION
#endif /* #ifndef _NDEBUG */

#define LOG_FATAL \
    if (_LOG_LEVEL >= 1) \
        BOOST_LOG_TRIVIAL(fatal) _LOG_LOCATION

#define LOG_ERROR \
    if (_LOG_LEVEL >= 2) \
        BOOST_LOG_TRIVIAL(error) _LOG_LOCATION

#define LOG_WARNING \
    if (_LOG_LEVEL >= 3) \
        BOOST_LOG_TRIVIAL(warning) _LOG_LOCATION

#define LOG_INFO \
    if (_LOG_LEVEL >= 4) \
        BOOST_LOG_TRIVIAL(info) _LOG_LOCATION

#define LOG_DEBUG \
    if (_LOG_LEVEL >= 5) \
        BOOST_LOG_TRIVIAL(debug) _LOG_LOCATION

#define LOG_TRACE \
    if (_LOG_LEVEL >= 6) \
        BOOST_LOG_TRIVIAL(trace) _LOG_LOCATION

#include <string>
#include <cstdio>

template<typename ... Args>
std::string STRING_FORMAT(const char* format, Args... args) {
    size_t size = snprintf(nullptr, 0, format, args...) + 1;
    char* buf = new char[size];
    snprintf(buf, size, format, args...);

    std::string str = std::string(buf, buf + size - 1);
    delete[] buf;
    return str;
}

#define FLOG_FATAL \
    LOG_FATAL << STRING_FORMAT

#define FLOG_ERROR \
    LOG_ERROR << STRING_FORMAT

#define FLOG_WARNING \
    LOG_WARNING << STRING_FORMAT

#define FLOG_INFO \
    LOG_INFO << STRING_FORMAT

#define FLOG_DEBUG \
    LOG_DEBUG << STRING_FORMAT

#define FLOG_TRACE \
    LOG_TRACE << STRING_FORMAT

#endif // BOOSTLOGGER_H
