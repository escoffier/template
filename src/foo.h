#ifndef __FOO__
#define __FOO__

template <typename T>
class Foo
{
  public:
    static int count() { return ctr; };
    static void incre() { ++ctr; };

  private:
    static int ctr;
};

template <typename T>
int Foo<T>::ctr = 10;

#endif