#include "taylors_header.hpp"
#include <stdexcept>

double kushekbaev::taylorCalc(double x, size_t max_members, double error)
{
  double next = x;
  double result = next;
  for (size_t i = 1; i < max_members; ++i)
  {
    next *= std::pow(x, 2*i+1)/(std::tgamma(2*i+2));
    result += next;
  }
  if (std::abs(next) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}
