#ifndef TAYLOR_SERIES_HPP
#define TAYLOR_SERIES_HPP

#include <cstddef>
#include <stdexcept>
#include <cmath>

namespace maslevtsov
{
  double taylorSeries(double x, size_t numberMax, double absError);
}

#endif