#include "brain.h"
double bocharov::sumf(double number, size_t k, double error)
{
  return f(number, k, error) + f2(number, k, error);
}
