#include "taylorseries.h"
#include <iostream>
#include <cstring>

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;

  if (std::cin.fail())
  {
    std::cerr << "input error\n";
    return 1;
  }
  if (left <= -1 || right >= 1 || left > right)
  {
    std::cerr << "input error\n";
    return 1;
  }

  constexpr double error = 0.001;
  constexpr double step = 0.05;

  lanovenko::table(left, right, k, error, step);
}

