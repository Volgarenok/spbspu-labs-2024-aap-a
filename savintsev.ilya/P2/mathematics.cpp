#include "mathematics.h"

double savintsev::calcFuncTaylor(double x, size_t k, const double error)
{
  double interim = 1.;
  double result = interim;
  for (size_t i = 1; i < k; ++i)
  {
    interim *= -(x * x) / i;
    result += interim;
  }
  if (std::abs(interim) > error)
  {
    throw std::logic_error("math-err");
  }
  return result;
}

double savintsev::calcFuncStd(double x)
{
  return std::exp(-std::pow(x, 2));
}
