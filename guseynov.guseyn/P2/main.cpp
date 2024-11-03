#include <iostream>

#include "taylor.hpp"

int main()
{
  constexpr double error = 0.001;
  constexpr double step = 0.05;
  double left = 0.0;
  double right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if ((!std::cin) || (left <= -1.0) || (right >= 1.0) || (left > right))
  {
    return 1;
  }
  guseynov::printTableForTaylor(left, right, k, step, error);
  std::cout << "\n";
  return 0;
}
