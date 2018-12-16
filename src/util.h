#ifndef __UTIL_H__
#define __UTIL_H__
#include <iostream>

template <typename T1, typename T2, typename T3>
T1 sum(T2 t1, T3 t2)
{
    return t1 + t2;
};

template <typename It>
auto func(It begin, It end) -> decltype(*begin)
{
    begin++;
    return *begin;
};

template<typename T >
void f3(T && val)
{
   T t = val;
   t++;
   if(t == val)
   {
       std::cout << "refrence\n";
   } 
   else
   {
       std::cout << "right refrence\n";
   }
};

#endif