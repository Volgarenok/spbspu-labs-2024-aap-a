#include <iostream>
#include "taylorSeries.hpp"

int main()
{
  constexpr double error = 0.01;
  constexpr double step = 0.05;
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if (!std::cin)
  {
    std::cerr << "The input could not be recognized\n";
    return 1;
  }
  if (left >= right)
  {
    std::cerr << "The interval is set incorrectly\n";
    return 1;
  }
  bool isLeft = -1.0 < left && left < 1.0;
  bool isRight = -1.0 < right && right < 1.0;
  if (!(isLeft && isRight))
  {
    std::cerr << "The interval is not in the definition area\n";
    return 1;
  }
  maslov::outTable(left, right, k, error, step);
}
