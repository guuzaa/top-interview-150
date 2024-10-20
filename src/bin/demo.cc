#include "array/array.h"

#include <iostream>

int main(int argc, char const *argv[]) {
  std::vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  std::cout << array::trap(height) << '\n';
  return 0;
}
