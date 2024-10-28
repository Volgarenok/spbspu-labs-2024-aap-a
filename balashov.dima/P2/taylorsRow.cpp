#include "taylorsRow.hpp"
#include <stdexcept>

double balashov::expTaylor(const double x,const size_t numberOfСalculations,const double error)
{
  double result = 1;
  double summand = 1;
  for (size_t i = 1; i < numberOfСalculations; i++)
  {
    summand = (x * summand) / i;
    result += summand;
  }
  if (std::abs(summand) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}
