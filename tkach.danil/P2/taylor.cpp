#include "taylorrow.h"
#include <stdexcept>

double tkach::coshTaylor(double x, size_t maxkolvo, const double error)
{
  double next = 1.0;
  double fact = 0.0;
  double sum = next;
  for (size_t i = 1; i < maxkolvo; ++i)
  {
    next *= (x*x)/((i+fact)*(i+1+fact));
    sum += next;
    fact++;
  }
  if (std::abs(next)>error)
  {
    throw std::logic_error("math-error");
  }
  return sum;
}
