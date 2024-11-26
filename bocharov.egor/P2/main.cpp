#include "taylor.h"
#include <iostream>
int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if (std::cin.fail() || bocharov::intervals(left, right) || k > 10)
  {
    std::cerr << "Incorect input\n";
    return 1;
  }
  const double error = 0.001;
  const double step = 0.05;
  for (auto i = left; i < right; i += step)
  {
    bocharov::table(i, k, error);
  }
}
