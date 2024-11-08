#include "taylorCalc.hpp"
#include <iostream>

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if (!std::cin.good())
  {
    std::cerr << "Input error" << "\n";
    return 1;
  }
  if ((left > right) or (left < -1) or (right > 1))
  {
    std::cerr << "Incorrect input" << "\n";
    return 1;
  }
  constexpr double error = 0.01, step = 0.123;
  shabalin::finalOutput(left, right, step, k, error);
}
