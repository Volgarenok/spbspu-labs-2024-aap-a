#include <iostream>
#include <cmath>
#include <stdexcept>
#include "header.hpp"

double kushekbaev::f(double x, size_t max_members, double error)
{
  double next = x;
  double result = next;
  for (size_t i = 1; i < max_members; ++i)
  {
    next *= pow(x, 2*i+1)/(tgamma(2*i+2));
    result += next;
  }
  if (std::abs(next) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}
