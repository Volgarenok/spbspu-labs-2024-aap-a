#include "taylorSeries.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cstring>

double maslov::fromCMath(double x)
{
  return std::exp(std::pow(-x, 2.0));
}

double maslov::fromTaylor(double x, size_t k, double error)
{
  double next = 1.0;
  double result = 1.0;
  double a = 0.0;
  for (size_t i = 1; i < k; i++)
  {
    a += 1.0;
    next *= (x * x)/(-a);
    result += next;
  }
  if (std::abs(result - fromCMath(x)) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}

void maslov::outString(double x, size_t k, double error)
{
  const char * errormsg = "<MATH_ERROR>";
  const size_t secondColumn = std::strlen(errormsg) + 2;
  constexpr size_t othersColumn = 10;

  std::cout << std::fixed << std::setprecision(2)
  << std::setw(othersColumn) << x << " ";
  try
  {
    std::cout << std::setprecision(5)
    << std::setw(secondColumn) << fromTaylor(x, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(secondColumn) << "<MATH_ERROR>";
  }
  std::cout << " " << std::setprecision(5)
  << std::setw(othersColumn) << maslov::fromCMath(x);
}

void maslov::outTable(double left, double right,
    size_t k, double error, double step)
{
  maslov::outString(left, k, error);
  std::cout << "\n";
  for (double i = left + step; i < right - step / 2.0; i += step)
  {
    maslov::outString(i, k, error);
    std::cout << "\n";
  }
  maslov::outString(right, k, error);
  std::cout << "\n";
}
