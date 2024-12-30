#ifndef SCALEOPERATIONS_HPP
#define SCALEOPERATIONS_HPP
#include <iostream>
#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"

namespace shabalin
{
  void scaleFunction(shabalin::Shape **shapes, size_t shapesCount, point_t scalePoint, double scaleK, std::ostream &out);
  void isoScale(Shape *shapeObj, point_t scalePoint, double scaleK);
}
#endif