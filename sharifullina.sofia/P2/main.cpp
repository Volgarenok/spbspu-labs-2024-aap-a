#include <iostream>
#include <cmath>
#include "output.hpp"
#include "cos_expnegx.hpp"

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;

  if (!std::cin)
  {
    std::cerr << "Not a number\n";
    return 1;
  }
  if (left <= -1 || right >= 1 || left > right)
  {
    std::cerr << "Incorrect interval\n";
    return 1;
  }

  constexpr double error = 0.001;
  constexpr double step = 0.05;

  sharifullina::output_table(left, right, k, step, error);
}
