#include "brain.h"
double bocharov::sumf(double number, size_t k, double error)
{
  return bocharov::f(number, k, error) + bocharov::f2(number, k, error);
}
