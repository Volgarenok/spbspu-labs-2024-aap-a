#include "brain.h"
#include <cmath>
#include <stdexcept>
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
  double sled = x;
  double resultat = x;
  if (k == 1)
  {
    return x;
  }
  for (size_t i = 2; i < k; i++)
  {
    sled = ((i - 1) * x * x * sled / 2) / (i + 1);
    if (i % 2 == 0)
    {
      resultat -= sled;
    }
    else if (i % 2 == 1)
    {
      resultat += sled;
    }
    else if (std::abs(sled) > error)
    {
      throw std::logic_error("Math error");
    }
  }
  return resultat;
}
