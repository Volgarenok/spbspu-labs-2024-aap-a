#include "taylor.hpp"

#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>

double guseynov::calculateUsingTaylorSeries(double x, size_t k, double error)
{
  double current = x;
  double result = x;
  double sign = -1;
  double divider = 3;
  for (size_t j = 1; j < k; j++)
  {
    current *= x * x;
    result += current * sign / divider;
    divider += 2;
    sign *= -1;
    if (std::abs(current * sign * (-1) / (divider - 2)) <= error)
    {
      return result;
    }
  }
  throw std::logic_error("math error");
}

void guseynov::printLineForTaylor(double current, size_t k, double error)
{
  std::cout << std::fixed;
  std::cout << std::setw(20) << current;
  try
  {
    std::cout << std::setw(20) << std::setprecision(6) << calculateUsingTaylorSeries(current, k, error);
    std::cout << std::setw(20) << std::setprecision(6) << std::atan(current);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(20) << "<MATH ERROR>";
  }
}

void guseynov::printTableForTaylor(double left, double right, size_t k, double step, double error)
{
  for (double i = left; i < (right - 0.25 * step); i += step)
  {
    printLineForTaylor(i, k, error);
    std::cout << "\n";
  }
  printLineForTaylor(right, k, error);
}
