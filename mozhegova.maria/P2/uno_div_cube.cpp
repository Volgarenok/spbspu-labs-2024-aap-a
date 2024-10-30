#include "uno_div_cube.hpp"
#include <cmath>
#include <stdexcept>

double mozhegova::uno_div_cube(double x, size_t k, double error)
{
  double next = 1.0;
  double result = next;
  for (size_t i = 0; i < k - 1; i++)
  {
    next *= (i + 3) * (-x) / (i + 1);
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
  return 1 / std::pow(1.0 + x, 3.0);
}
