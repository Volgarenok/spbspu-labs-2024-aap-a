#include "taylor.h"
#include "row.h"
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <cstring>

void aleksandrov::printRow(double i, size_t k, double error)
{
  constexpr const char* errorMessage = "<MATH ERROR>";
  constexpr size_t columnWidth = std::strlen(errorMessage);
  std::cout << std::setw(columnWidth) << std::left << std::fixed << std::setprecision(5) << i;
  try
  {
    std::cout << std::setw(columnWidth) << std::left << std::fixed << std::setprecision(5);
    std::cout << taylor(i, k, error);
  }
  catch (const std::logic_error& e)
  {
    std::cout << std::setw(columnWidth) << std::left;
    std::cout << errorMessage;
  }
  try
  {
    std::cout << std::setw(columnWidth) << std::right << std::fixed << std::setprecision(5);
    std::cout << sinxDivx(i);
  }
  catch (const std::logic_error& e)
  {
    std::cout << std::setw(columnWidth) << std::left << errorMessage;
  }
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

