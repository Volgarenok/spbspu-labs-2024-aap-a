#include "taylor_cos.hpp"
#include <cmath>
#include <stdexcept>
#include <cstring>
double nikonov::cos(double x, size_t numberMax, double absError)
{
  double next = (x * x) / 2;
  double result = 1 - next;
  for (size_t i = 1; i < numberMax; i++)
  {
    next *= (x * x) / ((2 * i + 1) * (2 * i + 2));
    result += (i % 2 == 0 ? next : next * -1);
  }
  if (std::abs(next) > absError)
  {
    throw std::logic_error("<MATH ERROR>");
  }
  return result;
}
double nikonov::stdcos(double x)
{
  return std::cos(x);
}
