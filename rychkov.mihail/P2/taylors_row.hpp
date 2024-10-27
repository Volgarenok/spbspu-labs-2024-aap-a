#ifndef TAYLORS_ROW_HPP
#define TAYLORS_ROW_HPP

#include <cstddef>

namespace rychkov
{
  namespace formulas
  {
    double calcUnoDivSqr(double x, size_t maxDepth, double absError);
    double calcUnoDivSqrWithStd(double x);
  }
}

#endif
