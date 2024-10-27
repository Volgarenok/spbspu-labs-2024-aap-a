#include "function.hpp"
#include <stdexcept>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <cmath>

double f(double x, size_t k, double error)
{
  double current_term = x;
  double result = 0.0;
  for (size_t i = 1; i < k; ++i)
  {
    current_term *= -x * x / (2 * i) * (2 * i - 1);
    result += current_term;
  }
  if (std::abs(result) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}

double stdf(double x)
{
  return std::cos(x);
}

void output(double x, size_t k, double error, size_t clmn)
{
  std::cout << std::setw(clmn) << x;
  std::cout << " ";
  try
  {
    std::cout << std::setw(clmn) << f(x, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(clmn) << e.what();
  }
  std::cout << std::setw(clmn) << stdf(x) << "\n";
}

void finalOutput(double left, double right, double step, size_t k, double error, size_t clmn)
{
   for (auto i = left; i < right; i += step)
  {
    output(i, k, error, clmn);
  }
  output(right, k, error, clmn);
}
