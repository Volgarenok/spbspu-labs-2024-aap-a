#include <stdexcept>
#include <cstddef>
#include <cmath>
#include "compute_giperbol_functions.hpp"

unsigned long long kalmbah::computeFactorial(size_t n)
{
  unsigned long long result = 1;
  for (size_t i = 1; i <= n; ++i)
  {
    result *= i;
  }
  return result;
}

double kalmbah::computeArcsinTaylor(double x, size_t n, double error)
{
  double sum = 0.0;
  for (size_t i = 0; i < n; ++i)
  {
    if (i == 0)
    {
      sum += x;
    }
    else if (i == 1)
    {
      sum += (-2.0 / 4.0) * (std::pow(x, 3) / 3.0);
    }
    else
    {
      double multiplire1 = (std::pow(-1, i) * computeFactorial(2 * i)) / (std::pow(2, (2 * i)) * std::pow(computeFactorial(i), 2));
      double multiplire2 = std::pow(x, (2 * i + 1)) / (2 * i + 1);
      double seriesElement = multiplire1 * multiplire2;
      sum += seriesElement;
    }
  }
  if (std::fabs(sum) < error)
  {
    throw std::runtime_error("<MATH ERROR>");
  }
  return sum;
}

double kalmbah::computeArctanTaylor(double x, size_t n, double error)
{
  double sum = 0.0;
  for (size_t i = 0; i < n; ++i)
  {
    double seriesElement = std::pow(x, (2 * i + 1)) / (2 * i + 1);
    sum += seriesElement;
  }
  if (std::fabs(sum) < error)
  {
    throw std::runtime_error("<MATH ERROR>");
  }
  return sum;
}
