#include <cmath>
#include "taylor.h"
namespace demehin
{
  double f(double x, size_t k, double error)
  {
    double next1 = 1;
    double next2 = x;
    double result = next1 + next2;
    for(size_t i = 2; i < k; ++i)
    {
    next2 = (next2 * x)/i
    result += next2;
    }
    return result;
  }
  double stdf(double x)
  {
    return exp(x);
  }
}
