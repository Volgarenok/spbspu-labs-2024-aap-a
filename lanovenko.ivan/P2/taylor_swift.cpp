#include "taylor_swift.h"
#include <cmath>
#include <stdexcept>

double lanovenko::f(double x, size_t k, double error)
{
  if (k <= 0)
  {
    throw std::logic_error("k cannot be negative");
  }
  if (error < 0)
  {
    throw std::logic_error("error cannot be negative");
  }
  double sum = 1;
  double c1 = 1;
  c1 *= 0.5 * x;
  sum += c1;
  for (size_t i = 2; i < k; i++)
  {
    c1 = c1 * ((2*i-3)/(2*i) * x * (-1));
    sum += c1;
    if (std::abs(c1) <= error)
    {
      return sum;
    }
  }

  throw std::logic_error("<MATH ERROR>"); 
}
