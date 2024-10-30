#include "tailor_series.hpp"
#include <iostream>
#include <cmath>

double gavrilova::v_taylor(double x, size_t nMax, double error)
{
  double absError = 0.0, result = 1.0, iTerm = 1.0;
  for (size_t i = 1; i < nMax; ++i) {
    iTerm = iTerm * (-1) * x;
    absError = iTerm * (i + 1) * (i + 2) / 2;
    result += absError;
    if (std::abs(absError) <= error) {
      return result;
    }
  }
  throw std::logic_error("!!!");
}

double gavrilova::v_cmath(double x)
{
  double result = 0.0;
  result = 1.0/std::pow(1 + x, 3.0);
  return result;
}

void gavrilova::output_str(double num, double v_taylor, double v_cmath)
{
  std::cout << std::fixed;
  std::cout.precision(12);
  std::cout << num << " " << v_taylor << " " << v_cmath;
}

void gavrilova::output_str(double num, const char * math_error, double v_cmath)
{
  std::cout << std::fixed;
  std::cout.precision(12);
  std::cout << num << " " << math_error << " " << v_cmath;
}
