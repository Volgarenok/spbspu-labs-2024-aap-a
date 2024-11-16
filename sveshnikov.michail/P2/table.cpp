#include "taylor.hpp"
#include <iostream>

void sveshnikov::table(double left, double right, size_t k)
{
  constexpr double error = 0.002;
  constexpr double step = 0.06;
  for (auto i = left; i < right; i += step)
  {
    sveshnikov::row(i, k, error);
    std::cout << "\n";
  }
  sveshnikov::row(right, k, error);
  std::cout << "\n";
}
