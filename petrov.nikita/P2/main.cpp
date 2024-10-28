#include "calculate_sinh.hpp"
#include <iostream>

int main()
{
  double start = 0.0, end = 0.0;
  size_t max = 0;
  std::cin >> start >> end >> max;
  if (!std::cin)
  {
    std::cerr << "ERROR:Invalid value\n";
    return 1;
  }
  if (start < -1.0 || start > 1.0 || end < -1.0 || end > 1.0 || start > end)
  {
    std::cerr << "ERROR:Invalid range\n";
    return 1;
  }
  constexpr double abs_error = 0.1;
  constexpr double step = 0.05;
  constexpr unsigned int precision = 6;
  std::cout.precision(precision);
  std::cout << std::fixed;
  petrov::outputTable(start, end, max, abs_error, step, precision);
}

