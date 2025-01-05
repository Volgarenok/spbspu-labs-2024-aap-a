#ifndef GETSHAPEINFO_HPP
#define GETSHAPEINFO_HPP

#include <iostream>
#include <cstddef>
#include "shape.hpp"

namespace dribas
{
  int getShapeInfo(std::istream& input, std::ostream& error, std::ostream& output, Shape** myShapes);
  void clear(Shape ** myshape, size_t shapeCount);
  double getAllArea(dribas::Shape** myShapes, size_t shapeCount);
}

#endif
