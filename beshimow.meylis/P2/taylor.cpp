#include "taylor.hpp"
#include <cmath>
#include <stdexcept>

namespace beshimow
{
  double taylor_sin(double x, size_t k, double error)
  {
    double sum = 0.0;
    double term = x;

    for (size_t n = 1; n <= k; ++n)
    {
      sum += term;
      double nextTerm = -term * x * x / ((2 * n) * (2 * n + 1));

      if (std::abs(nextTerm) < error)
      {
        break;
      }

      term = nextTerm;
    }

    return sum;
  }
}
