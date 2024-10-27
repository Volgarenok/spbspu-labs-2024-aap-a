#ifndef FINDINGTYLOR_HPP
#define FINDINGTYLOR_HPP
#include <cstddef>
#include <stdexcept>
#include <cmath>

namespace zakirov
{
  double zakirov::find_atanh(double point, size_t addition_depth, const double kError);
  double zakirov::get_atanh(double point);
};

#endif