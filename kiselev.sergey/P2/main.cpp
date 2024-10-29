#include "taylor.h"
#include <iostream>
int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if (std::cin.fail() || kiselev::input_check1(left, right) || kiselev::input_check2(right, k))
  {
    std::cerr << "Incorrect input\n";
    return 1;
  }
  const double error = 0.0052;
  const double step = 0.05;
  for (auto i = left; i <= right; i += step)
  {
    kiselev::output_table(i, k, error);
  }
}
