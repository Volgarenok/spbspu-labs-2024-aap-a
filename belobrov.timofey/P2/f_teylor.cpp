#include "f_teylor.hpp"
#include <cmath>
#include <stdexcept>

double belobrov::f_teylor(double x, size_t k, double error)
{
  double teylor_result = x;
  double z = -1;
  double d_x = x;

  for (size_t n = 1; n < k; ++n)
  {
    d_x *= x * x;
    double coefficient = z / (2 * n * (2 * n + 1));
    teylor_result += coefficient * d_x;
    z *= -1;
  }

  double ln_result = std::log(x + std::sqrt(x * x + 1));

  if (std::abs(teylor_result - ln_result) > error)
  {
    throw std::logic_error("<MATH ERROR>");
  }

  return teylor_result;
}
