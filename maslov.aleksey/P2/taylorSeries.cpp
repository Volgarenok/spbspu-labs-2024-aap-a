#include "taylorSeries.hpp"

double maslov::fromCMath(double x)
{
  return exp(pow(-x, 2.0));
}

double maslov::fromTaylor(double x, size_t k, double error)
{
  double next = 1.0;
  double result = 1.0;
  double a = 0.0;
  for (size_t i = 1; i < k; i++)
  {
    a += 1.0;
    next *= (x * x)/(-a);
    result += next;
  }
  if (std::abs(result - fromCMath(x)) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}

void maslov::outString(double x, size_t k, double error)
{
  std::cout << x << " ";
  try
  {
    std::cout << fromTaylor(x, k, error) << " ";
  }
  catch (const std::logic_error & e)
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
