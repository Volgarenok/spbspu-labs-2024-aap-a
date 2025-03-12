#ifndef SCALE_ISOTROPICALLY_AND_OUTPUT_DATA_HPP
#define SCALE_ISOTROPICALLY_AND_OUTPUT_DATA_HPP
#include "base-types.hpp"
#include "composite-shape.hpp"

namespace petrov
{
  void scaleIsotropicallyAndOutputData(const point_t & scale_point, double k, CompositeShape & composite_shape);
}
#endif
