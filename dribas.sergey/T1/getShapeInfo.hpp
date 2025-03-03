#ifndef GETSHAPEINFO_HPP
#define GETSHAPEINFO_HPP

#include <cstddef>
#include <iostream>
#include "composite-shape.hpp"
#include "shape.hpp"

namespace dribas
{
  CompositeShape getShapeInfo(std::istream& input, std::ostream& error, CompositeShape shapes, double* scalingFactor);
  void scaleOne(Shape& t, double ratio, point_t point);
}
#endif
