#ifndef __VARIADIC_H__
#define __VARIADIC_H__
#include <ostream>

template <typename T>
std::ostream &myprint(std::ostream &os, const T &t)
{
    return os << t;
};

template <typename T, typename... Args>
std::ostream &myprint(std::ostream &os, const T &t, Args &... rest)
{
    os << t << ", ";
    return myprint(os, rest...);
};
#endif