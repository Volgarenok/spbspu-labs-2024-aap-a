#include "taylor.h"
#include <cmath>
#include <stdexcept>
double bocharov::f(double x, size_t k, double error)
{
  if (k <= 0)
  {
    throw std::logic_error("The number of terms must be a positive number");
  }
  if (error < 0)
  {
    throw std::logic_error("The absolute error must be a positive number.");
  }
  double next = 1;
  double result = next;
  for (size_t i = 2; i < k; i++)
  {
    if (i % 2 != 0)
    {
      next = next * (0 - (2 * (i - 1) - 1) * x / (2 * (i - 1)));
    }
    else
    {
      next = next * ((2 * (i - 1) - 1) * x / (2 * (i - 1)));
    }
    result += next;
  }
  if (std::abs(next) > error)
  {
    throw std::logic_error("Math error");
  }
  return result;
}

double bocharov::f2(double x, size_t k, double error)
{
  if (k <= 0)
  {
    throw std::logic_error("The number of terms must be a positive number");
  }
  if (error < 0)
  {
    throw std::logic_error("The absolute error must be a positive number.");
  }
  double next = x;
  double result = x;
  if (k == 1)
  {
    return x;
  }
  for (size_t i = 2; i < k; i++)
  {
    next = ((i - 1) * x * x * next / 2) / (i + 1);
    if (i % 2 == 0)
    {
      result -= next;
    }
    else if (i % 2 == 1)
    {
      result += next;
    }
    else if (std::abs(next) > error)
    {
      throw std::logic_error("Math error");
    }
  }
  return result;
}
