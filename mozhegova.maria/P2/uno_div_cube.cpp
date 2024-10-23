#include "uno_div_cube.hpp"
#include <cmath>
#include <stdexcept>

double mozhegova::uno_div_cube(double x, size_t k, double error)
{
  double next = 1;
  double result = next;
  for (size_t i = 1; i < k; i++)
  {
    next *= ((1 + i) * (2 + i)) / 2 * (- x);
    result += next;
  }
  if (std::abs(next) > error)
  {
    throw std::logic_error("math_error");
  }
  return result;
}

double mozhegova::uno_div_cube_cmath(double x)
{
  return 1 / pow(1.0 + x, 3.0);
}
