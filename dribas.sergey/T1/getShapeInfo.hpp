#ifndef GETSHAPEINFO_HPP
#define GETSHAPEINFO_HPP

#include <iostream>
#include <cstddef>
#include "shape.hpp"

namespace dribas
{
  int getShapeInfo(std::istream& input, std::ostream& error, std::ostream& output, Shape** myShapes);
  void clear(Shape ** myshape, size_t shapeCount);
  double getAllArea(Shape** myShapes, size_t shapeCount);
  void scaling(Shape** myShapes, size_t shapeCount, point_t center, double ratio);
}

#endif
