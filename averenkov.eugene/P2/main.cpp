#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include "taylor.h"

int main()
{
  constexpr double step = 0.05;
  constexpr double error = 0.01;
  double left = 0.0;
  double right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if (!std::cin || left < -1 || right > 1 || left > 1 || right < -1 || right < left)
  {
    std::cerr << "INCORRECT INPUT";
    return 1;
  }
  for (double i = left; i <= right; i += step)
  {
    averenkov::outline(i, k, error);
    std::cout << "\n";
  }
  averenkov::outline(right, k, error);
  std::cout << "\n";
}
