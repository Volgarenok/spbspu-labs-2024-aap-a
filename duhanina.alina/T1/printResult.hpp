#ifndef PRINTRESULT_HPP
#define PRINTRESULT_HPP
#include "rectangle.hpp"
#include "ellipse.hpp"
#include "circle.hpp"
#include <iostream>

namespace duhanina
{
  void printFiguresInfo(Shape** shapes, size_t shapeCount);
  void processScaling(Shape** shapes, size_t shapeCount, point_t point, double scalingFactor);
}

#endif
