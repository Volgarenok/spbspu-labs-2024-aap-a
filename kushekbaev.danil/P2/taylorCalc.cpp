#include "sinh_taylor_calculator.hpp"
#include <stdexcept>
#include <cmath>

double kushekbaev::taylorCalc(double x, size_t max_members, double error)
{
  double next = x;
  double result = next;
  double x_squared = x * x;

  for (size_t i = 1; i < max_members; i++)
  {
    next *= x_squared / (2 * i * (2 * i + 1));
    result += next;
  }

  if (std::abs(next) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}
