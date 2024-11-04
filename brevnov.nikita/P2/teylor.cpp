#include "teylor.hpp"
#include <cmath>
#include <stdexcept>

double brevnov::f(double x, size_t k, double error)
{
  double result = x;
  for (size_t i = 1; i < k; ++i)
  {
    result += (std::pow(-1, i) * std::pow(x, 2 * i + 1)) / (2 * i + 1);
  }
  if (std::abs(result) - std::abs(std::atan(x)) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}
