#include "tyler_row.h"
#include <cmath>
#include <stdexcept>

double finaev::fsqrt(double x, size_t k, double error)
{
  if (k <= 0)
  {
    throw std::logic_error("uncorrect values");
  }
  if (error < 0)
  {
    throw std::logic_error("uncorrect values");
  }
  double res = 1;
  double el = 1;
  el *= 0.5 * x;
  res += el;
  for (size_t i = 2; i < k; i++)
  {
    el *= ((2 * i - 3) / (2 * i)) * x * (-1);
    res += el;
    if (std::abs(el) <= error)
    {
      return res;
    }
  }
  throw std::logic_error("math error");
}
