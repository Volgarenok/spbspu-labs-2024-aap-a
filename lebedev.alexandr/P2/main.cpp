#include "taylor_raw.hpp"
#include "output.hpp"
#include <iostream>

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if (std::cin.fail())
  {
    std::cerr << "Incorrect input\n";
    return 1;
  }
  if (left <= -1 || right >= 1 || left > right)
  {
    std::cerr << "Incorrect interval\n";
    return 1;
  }

  constexpr double step = 0.05;
  constexpr double error = 0.001;

  lebedev::output_table(left, right, k, error, step);
}
