#ifndef SCALEOPERATIONS_HPP
#define SCALEOPERATIONS_HPP
#include "base-types.hpp"
#include "shape.hpp"
#include <iostream>
#include <cstddef>

namespace shabalin
{
  void scaleFunction(shabalin::Shape **shapes, size_t shapesCount, point_t scalePoint, double scaleK, std::ostream &out);
  void isoScale(Shape *shapeObj, point_t scalePoint, double scaleK);
}
#endif
