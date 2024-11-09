#include "taylor.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
double averenkov::lnf(double x)
{
  return std::log(x + std::sqrt(x * x + 1));
}
double averenkov::f(double x, size_t k, double error)
{
  double next = x;
  double result = x;
  if (k == 1)
  {
    return x;
  }
  for (size_t i = 2; i < k; ++i)
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
      throw std::logic_error("math-error");
    }
  }
  return result;

}

void averenkov::outline(double x, size_t k, double error)
{
  std::cout << std::setw(15) << x;
  std::cout << std::setw(15) << averenkov::lnf(x) << " ";
  try
  {
    std::cout << std::setw(15) << averenkov::f(x, k, error) << "\n";
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(15) << "<MATH ERROR>\n";
  }
}
