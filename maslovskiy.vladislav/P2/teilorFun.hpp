#ifndef TEILOR_FUN_HPP
#define TEILOR_FUN_HPP

#include <cstddef>

namespace maslovskiy
{
  constexpr double default_error = 0.001;
  double teilorCos(const double x, const size_t k, const double error);
}

#endif
