#include <stdexcept>
#include "taylorsRow.hpp"

namespace balashov
{
  double EXP_X(double x, size_t numberOfTerms, double error)
  {
    double result = 1;
    double summand = 1;
    for (size_t i = 1; i < numberOfTerms; i++)
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
}
