#ifndef SCALE_ISOTROPICALLY_HPP
#define SCALE_ISOTROPICALLY_HPP
#include "shape.hpp"
#include "cstddef"
namespace petrov
{
  void scaleIsotropically(point_t scale_point, size_t k, Shape * shape);
}
#endif