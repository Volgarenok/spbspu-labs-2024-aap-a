#include "taylor.h"
double bocharov::sumf(double number, size_t k, double error)
{
  return f(number, k, error) + f2(number, k, error);
}

double bocharov::sumf2(double number)
{
  return sqrt1_x(number) + lnf(number);
}
