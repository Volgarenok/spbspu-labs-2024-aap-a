#include "taylor_series.hpp"

double maslevtsov::taylorSeries(double x, size_t k, double error)
{
  double next = 1;
  double n = 1.0;
  double result = next;
  
  for (size_t i = 1; i < k; ++i)
  {
    next *= x * x * ((n) / (n + 1.0));
    result += next;
    n += 2;
  }

  if (std::abs(next) > error)
  {
    throw std::logic_error("math_error");
  }
  
  return result;
}