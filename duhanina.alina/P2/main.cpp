#include "titletaylor.h"
#include <iostream>

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;

  if (!std::cin.good())
  {
    std::cerr << "Failed to recognize input" << "\n";
    return 1;
  }
  if (left > right || left >= 1 || left <= -1 || right >= 1 || right <= -1)
  {
    std::cerr << "Incorrect interval" << "\n";
    return 1;
  }

  constexpr double error = 0.001;
  constexpr double step = 0.1;
  for (auto i = left; i < right; i += step)
  {
    duhanina::output(i, k, error);
  }
  duhanina::output(right, k, error);
  return 0;
}
