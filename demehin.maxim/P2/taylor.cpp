#include <cmath>
#include <stdexcept>
#include "taylor.h"
#include <iostream>

double demehin::f(double x, size_t k, double error)
{
  double next1 = 1;
  double next2 = x;
  double result = next1 + next2;
  for(size_t i = 2; i < k; ++i)
  {
    next2 = (next2 * x)/i;
    result += next2;
  }
  if(std::abs(next2) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}

double demehin::stdf(double x)
{
  return exp(x);
}

void demehin::output(double left, double right, const double step, const double error, const size_t k)
{
  for(auto i = left; i < right; i += step)
  {
    std::cout << i << " ";
    try
    {
      std::cout << demehin::f(i, k, error);
    }
    catch(const std::logic_error & e)
    {
      std::cout << "<MATH ERROR>";
    }
    std::cout << " " << demehin::stdf(i) << "\n";
  }
  std::cout << right << " ";
  try
  {
    std::cout << " " << demehin::f(right, k, error);
  }
  catch(const std::logic_error & e)
  {
    std::cout << "<MATH ERROR>";
  }
  std::cout << " " << demehin::stdf(right) << "\n";
}
