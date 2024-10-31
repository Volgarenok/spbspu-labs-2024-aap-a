#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <cstring>
#include "taylor.h"
#include "row.h"

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if (!std::cin)
  {
    std::cerr << "Input was incorrect!\n";
    return 1;
  }
  if (left <= -1.0 || right >= 1.0 || left >= right || k <= 0)
  {
    std::cerr << "Interval was set incorrectly!\n";
    return 1;
  }
  constexpr double error = 0.0069;
  constexpr double step = 0.05;
  for (auto i = left; i < right; i += step)
  {
    aleksandrov::printRow(i, k, error);
    std::cout << "\n";
  }
  aleksandrov::printRow(right, k, error);
  std::cout << "\n";
}

