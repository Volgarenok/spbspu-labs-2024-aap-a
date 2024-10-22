#ifndef TAYLOR_SERIES_HPP
#define TAYLOR_SERIES_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>

namespace maslevtsov
{
  double taylorSeries(double x, size_t k, double error);
}

#endif