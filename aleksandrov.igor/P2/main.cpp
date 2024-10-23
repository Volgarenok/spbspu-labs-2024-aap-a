#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <cstring>
#include "namespace.h"

void aleksandrov::printString(double i, size_t k, double error)
{
  const char* errorMessage = "<MATH ERROR>";
  const size_t columnWidth = std::strlen(errorMessage);
  size_t cw = columnWidth;
  std::cout << std::setw(cw) << std::left << std::setprecision(5) << i;
  try
  {
    std::cout << std::setw(cw) << std::left << std::setprecision(5) << aleksandrov::taylor(i, k, error);
  }
  catch (const std::logic_error& e)
  {
    std::cout << std::setw(cw) << std::left << errorMessage;
  }
  try
  {
    std::cout << std::setw(cw) << std::right << std::setprecision(5) << aleksandrov::sinx_divx(i);
  }
  catch (const std::logic_error& e)
  {
    std::cout << std::setw(cw) << std::left << errorMessage;
  }
  std::cout << "\n";
}

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
  const double error = 0.069;
  const double step = 0.05;
  for (auto i = left; i < right; i += step)
  {
    aleksandrov::printString(i, k, error);
  }
  aleksandrov::printString(right, k, error);
}

