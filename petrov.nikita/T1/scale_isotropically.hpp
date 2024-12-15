#ifndef SCALE_ISOTROPICALLY_HPP
#define SCALE_ISOTROPICALLY_HPP
#include "shape.hpp"
#include "cstddef"
namespace petrov
{
  void scaleIsotropicallyAndOutputData(point_t scale_point, double k, Shape ** shape, size_t count);
}
#endif