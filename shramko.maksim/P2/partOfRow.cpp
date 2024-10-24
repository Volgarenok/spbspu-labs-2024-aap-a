#include "partOfRow.hpp"
#include <stdexcept>
#include <iostream>

double shramko::partOfRow(double x, size_t k, double error)
{
  double taylor = 1;
  double adding = 1;

  for (size_t i = 1; i < k; i += 2)
  {
    adding = -(x * x * adding) / ((i + 1) * (i + 2));
    taylor += adding;
  }
  if (adding > error)
  {
    throw std::logic_error("math-error");
  }
  return taylor;
}

