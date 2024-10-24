#include "taylor_swift.hpp"
#include <cmath>
#include <stdexcept>

double lebedev::sinus(double x, size_t k, double error)
{
  double next = x;
  double result = next;
  double st = 2.0;
  for (size_t i = 0; i < k - 1; ++i)
  {
    next *= (-x * x);
    next /= st++;
    next /= st++;
    result += next;
  }
  if (std::abs(next) > error)
  {
    throw std::logic_error("math_error");
  }
  return result;
}

double lebedev::sinus_cmath(double x)
{
  return sin(x);
}