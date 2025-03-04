#include <stdexcept>
#include <cstddef>
#include <cmath>
#include "taylor_functions.h"
unsigned long long kalmbah::factorial(size_t n)
{
  unsigned long long result = 1;
  for (size_t i = 1; i <= n; ++i) {
    result *= i;
  }
  return result;
}
double kalmbah::arcsinTaylor(double x, size_t n, double error)
{
  double sum = 0;
  for (size_t i = 0; i < n; ++i) {
    if (i == 0){
      sum += x;
    } else if (i == 1) {
      sum += (-2/4)*(pow(x,3)/3);
    } else {
      double p1 = (pow(-1, i) * kalmbah::factorial(2 * i)) / (pow(2, (2 * i)) * pow(kalmbah::factorial(i), 2));
      double p2 = pow(x, (2 * i + 1)) / (2 * i + 1);
      double element_summirovania = p1 * p2;
      sum += element_summirovania;
      if (fabs(element_summirovania) < error) {
        throw std::runtime_error("<MATH ERROR>");
      }
    }
  }
  return sum;
}
double kalmbah::arctanTaylor(double x, size_t n, double error)
{
  double sum = 0;
  double element_summirovania = 0;
  for (size_t i = 0; i < n; ++i) {
    element_summirovania = pow(x, (2 * i + 1)) / (2 * i + 1);
    sum += element_summirovania;
    if (fabs(element_summirovania) < error) {
      throw std::runtime_error("<MATH ERROR>");
    }
  }
  return sum;
}
