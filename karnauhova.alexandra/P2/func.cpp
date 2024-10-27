#include "namespace.hpp"

double karnauhova::f(double x, size_t k, double error)
{
  double next = x;
  double result = next;
  for (size_t i = 1; i < k;++i)
  {
    next = 1.0;
    for (size_t j = 0; j < (i*2+1); ++j)
    {
      next*=x;
    }
    for (double j = 1; j < (i*2+2); ++j)
    {
      next/=j;
    }
    if (i%2 == 0)
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

void karnauhova::output_row(double x, size_t k, double error, size_t width)
{
  std::cout << std::setw(width) << x;
  std::cout << " ";
  try
  {
    std::cout << std::setw(width) << karnauhova::f(x, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(width) << "<MATH ERROR>";
  }
  std::cout << std::setw(width) << karnauhova::stdf(x);
  std::cout << "\n";
}

void karnauhova::output_table(double left, double right, double step, size_t k, double error, size_t width)
{
  for (auto i = left; i < right; i += step)
  {
    karnauhova::output_row(i, k, error, width);
  }
  karnauhova::output_row(right, k, error, width);
}
