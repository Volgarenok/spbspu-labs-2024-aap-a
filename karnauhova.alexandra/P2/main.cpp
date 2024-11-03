#include <iostream>
#include "count_sin.hpp"
#include "create_table.hpp"

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if (!std::cin.good())
  {
    std::cerr << "Input error";
    return 1;
  }
  if ((left > right) or (left < -1) or (right > 1))
  {
    std::cerr << "Incorrect input";
    return 1;
  }
  constexpr double error = 0.001;
  constexpr double step = 0.05;
  constexpr size_t width = 13;
  karnauhova::output_table(left, right, step, k, error, width);
}
