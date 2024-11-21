#include "taylor.h"
#include <stdexcept>
#include <cmath>

double ivanova::arctg(double x, size_t k, double error)
{
  double next = x;
  double result = next;
  for (size_t i = 1; i < k; ++i)
  {
    next *= x * x;
    next /= (2 * i) * (2 * i + 1);
    result += next;
  }
  if (std::abs(next) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}

double ivanova::std_arctg(double x)
{
  return std::atan(x);
}

double ivanova::exp(double x, size_t k, double error)
{
  double next = 1;
  double result = next;
  for (size_t i = 1; i < k; ++i)
  {
    next *= x / i;
    result += next;
  }
  if (std::abs(next) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}

double ivanova::std_exp(double x)
{
  return std::exp(x);
}
