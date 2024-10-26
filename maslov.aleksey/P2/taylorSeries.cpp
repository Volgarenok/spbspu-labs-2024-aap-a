#include "taylorSeries.hpp"

double maslov::fromCMath(double x)
{
  return exp(pow(-x, 2.0));
}

double maslov::fromTaylor(double x, size_t k, double error)
{
}

void maslov::outString(double x, size_t k, double error)
{
  std::cout << x << " ";
  try
  {
    std::cout << fromTaylor(x, k, error) << " ";
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << "<MATH_ERROR>";
  }
  std::cout << maslov::fromCMath(x);
  std::cout << "\n";
}

void maslov::outTable(double left, double right,
  size_t k, double error, double step)
{
  for (double i = left; i < right; i += step)
  {
    maslov::outString(i, k, error);
  }
}
