#ifndef TAYLORS_ROW_HPP
#define TAYLORS_ROW_HPP

#include <cstddef>

namespace balashov
{
  double expTaylor(double x, size_t numberOfTerms, double error);
}

#endif
