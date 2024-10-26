#include "petrov_namespace.hpp"
#include <iostream>

double petrov::calculateByTailor(double x, size_t k, double error)
{
  double result = x;
  unsigned int count = 1;
  for (size_t i = 1; i < k; i++)
  {
    count += 2;
    double numerator = x;
    double denominator = 1.0;
    for (size_t j = 1; j < count; j++)
    {
      numerator *= x;
    }
    for (size_t j = 2; j <= count; j++)
    {
      denominator *= j;
    }
    result += numerator / denominator;
  }
  return result;
}
