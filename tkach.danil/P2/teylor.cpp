#include <iostream>
#include <cstddef>
#include "all.h"
double tkach::teylor_row(double x, size_t k, const double error)
{
  double next = 1.0;
  double fact = 0.0;
  double sum = next;
  for(size_t i = 1; i < k; ++i)
  {
    next *= (x*x)/((i+fact)*(i+1+fact));
    sum += next;
    fact++;
  }
  if (next>error)
  {
    throw std::logic_error("math-error");
  }
  return sum;
}
