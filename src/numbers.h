#ifndef __NUMBERS__
#define __NUMBERS__

template <typename T = int>
class Numbers
{
  public:
    Numbers(T v = 0) : val(v) {}
    T value() { return val; }
    void value(T v) { val = v; }

  private:
    T val;
};
#endif