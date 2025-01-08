#ifndef SCALE_ISOTROPICALLY_AND_OUTPUT_DATA_HPP
#define SCALE_ISOTROPICALLY_AND_OUTPUT_DATA_HPP
#include "shape.hpp"
#include "cstddef"
namespace petrov
{
  void scaleIsotropicallyAndOutputData(point_t scale_point, double k, Shape ** shape, size_t created);
}
#endif
