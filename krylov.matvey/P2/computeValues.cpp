#include <cmath>
#include <stdexcept>
#include "computeValues.hpp"

double krylov::f(double x, size_t k, double error)
{
  double result = 1;
  double previous_term = 1;
  double current_term = 0;
  int factor = 1;
  int divider = 1;
  for (size_t i = 1; i < k; i++)
  {
    divider = divider * (factor + 1) * (factor + 2);
    current_term = (previous_term * x * x) / divider;
    if (i % 2 == 0)
    {
      result += current_term;
      previous_term = current_term;
    }
    else
    {
      result -= current_term;
      previous_term = current_term;
    }
    factor += 2;
  }
  if (std::abs(previous_term) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}

double krylov::sinx_div_x(double x)
{
  return std::sin(x) / x;
}
