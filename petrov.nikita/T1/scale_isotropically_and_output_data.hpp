#ifndef SCALE_ISOTROPICALLY_AND_OUTPUT_DATA_HPP
#define SCALE_ISOTROPICALLY_AND_OUTPUT_DATA_HPP
#include "composite-shape.hpp"
#include "cstddef"
namespace petrov
{
  void scaleIsotropicallyAndOutputData(point_t scale_point, double k, CompositeShape * composite_shape);
}
#endif
