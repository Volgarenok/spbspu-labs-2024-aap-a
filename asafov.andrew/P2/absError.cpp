#include "func.hpp"

namespace asafov {
  double absError(double x, size_t k)
  {
    double res = (k % 2 == 0) ? (-1) : (1);
    for (size_t i = k; i > 0; i--)
    {
      res = res * x * x / i;
    }
    return res;
  }
}
