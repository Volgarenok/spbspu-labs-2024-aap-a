#include <iostream>
#include <cstddef>
#include "all.h"
double TeylorRow(double x, size_t k, double error)
{
  double next = 1;
  double fact = 0;
  double sum = next;
  for(size_t i = 1; i < k; ++i)
  {
    next *= (x*x)/((i+fact)*(i+1+fact));
    sum+=next;
    fact++;
  }
  std::cout << error << "\n";
  return sum;
}
