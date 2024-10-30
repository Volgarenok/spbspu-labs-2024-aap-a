#include "func.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>

double karnauhova::f(double x, size_t k, double error)
{
  double next = x;
  double result = next;
  for (size_t i = 1; i < k; ++i)
  {
    next = 1.0;
    for (size_t j = 0; j < (i * 2 + 1); ++j)
    {
      next *= x;
    }
    for (double j = 1; j < (i * 2 + 2); ++j)
    {
      next /= j;
    }
    if (i % 2 == 0)
    {
      result += next;
    }
    else
    {
      result -= next;
    }
  }
  if (std::abs(next) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}

double karnauhova::stdf(double x)
{
  return std::sin(x);
}


