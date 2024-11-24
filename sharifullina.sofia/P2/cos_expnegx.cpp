#include "cos_expnegx.hpp"
#include <cmath>
#include <stdexcept>

double sharifullina::cos(double x, size_t k, double error)
{
  double next = (x * x) / 2;
  double result = 1 - next;
  for (size_t i = 1; i < k - 1; ++i)
  {
    next *= (x * x) / ((2 * i + 1) * (2 * i + 2));
    result += (i % 2 ? next : next * -1);
  }
  if (std::abs(next) > error)
  {
    throw std::logic_error("MATH_ERROR");
  }
  return result;
}
double sharifullina::exp_negx(double x, size_t k, double error)
{
  double next = -1 * x;
  double result = 1 + next;
  for (size_t i = 0; i < k - 2; ++i)
  {
    next *= -1 * (x / (i + 2));
    result += next;
  }
  if (std::abs(next) > error)
  {
    throw std::logic_error("MATH_ERROR");
  }
  return result;
}

double sharifullina::cos_and_exp(double x, size_t k, double error)
{
  return cos(x, k, error) + exp_negx(x, k, error);
}

double sharifullina::cos_and_exp_cma(double x)
{
  return cos_cmath(x) + exp_negx_cmath(x);
}
double sharifullina::cos_cmath(double x)
{
  return std::cos(x);
}
double sharifullina::exp_negx_cmath(double x)
{
  return std::exp(-x);
}
