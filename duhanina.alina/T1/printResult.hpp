#ifndef PRINTRESULT_HPP
#define PRINTRESULT_HPP
#include <ostream>
#include "base-types.hpp"
#include "shape.hpp"

namespace duhanina
{
  void outFigures(std::ostream& out, const Shape* const* shapes, size_t shapeCount);
  double calcArea(const Shape* const* shapes, size_t shapeCount);
  void printFiguresInfo(std::ostream& out, const Shape* const* shapes, size_t shapeCount);
  void processScaling(Shape* const* shapes, size_t shapeCount, point_t point, double scalingFactor);
}

#endif
