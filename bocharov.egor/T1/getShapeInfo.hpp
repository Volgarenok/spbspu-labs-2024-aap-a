#ifndef GETSHAPEINFO_HPP
#define GETSHAPEINFO_HPP
#include <iostream>
#include <cstddef>
#include "shape.hpp"

namespace bocharov
{
  size_t getShapeInfo(std::istream & input, std::ostream & error, std::ostream & output, Shape ** shapes);
  void clear(Shape ** shapes, size_t shapeCount);
  double getAllArea(const Shape * const * shapes, size_t shapeCount);
  void scaling(Shape ** shapes, size_t shapeCount, point_t center, double ratio);
}

#endif
