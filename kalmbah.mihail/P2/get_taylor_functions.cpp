#include <stdexcept>
#include <cstddef>
#include <cmath>
#include "get_taylor_functions.h"

unsigned long long kalmbah::getFactorial(size_t n)
{
  unsigned long long result = 1;
  for (size_t i = 1; i <= n; ++i) {
    result *= i;
  }
  return result;
}

double kalmbah::getArcsinTaylor(double x, size_t n, double error)
{
  double sum;
  for (size_t i = 0; i < n; ++i) {
    if (i == 0){
      sum += x;
    } else if (i == 1) {
      sum += (-2/4)*(std::pow(x,3)/3);
    } else {
      double multiplire1 = (std::pow(-1, i) * getFactorial(2 * i)) / (std::pow(2, (2 * i)) * std::pow(getFactorial(i), 2));
      double multiplire2 = std::pow(x, (2 * i + 1)) / (2 * i + 1);
      double elementSummirovania = multiplire1 * multiplire2;
      sum += elementSummirovania;
    }
  }
  if (std::fabs(sum) < error) {
    throw std::runtime_error("<MATH ERROR>");
  }
  return sum;
}

double kalmbah::getArctanTaylor(double x, size_t n, double error)
{
  double sum = 0;
  double elementSummirovania;
  for (size_t i = 0; i < n; ++i) {
    elementSummirovania = std::pow(x, (2 * i + 1)) / (2 * i + 1);
    sum += elementSummirovania;
  }
  if (std::fabs(sum) < error) {
    throw std::runtime_error("<MATH ERROR>");
  }
  return sum;
}
