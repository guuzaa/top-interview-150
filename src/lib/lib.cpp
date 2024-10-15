#include "lib/lib.h"

template <typename T>
T add(T a, T b) {
  return a + b;
}

template int add(int a, int b);
template unsigned int add(unsigned int a, unsigned int b);
template long add(long a, long b);
template unsigned long add(unsigned long a, unsigned long b);
template long long add(long long a, long long b);
template unsigned long long add(unsigned long long a, unsigned long long b);