#include "Tylor.h"
#include <cmath>
#include <stdexcept>

namespace lungu
{
  double func_Tylor(double x, double absError, int numberMax)
  {
    double sum = 1.0;
    double term = 1.0;
    int n = 1;
    do {
      term *= -x * x / (2 * n - 1) / (2 * n);
      sum += term;
      n++;
      if (n > numberMax) {
        throw std::runtime_error("Max number of operands reached");
      }
    } while (std::fabs(term) > absError);
    return sum;
  }
}
