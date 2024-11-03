#include <iostream>
#include "taylor_output.hpp"
int main()
{
  constexpr double step = 0.1, absError = 0.001;
  double left = 0.0, right = 0.0;
  size_t numberMax = 0;
  std::cin >> left >> right >> numberMax;
  if (!std::cin || right > 1 || left < -1 || left > right)
  {
    std::cerr << "ERROR: incorrect input" << "\n";
    return 1;
  }
  nikonov::table_output(left, right, step, numberMax, absError);
}
