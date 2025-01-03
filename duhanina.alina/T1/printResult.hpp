#ifndef PRINTRESULT_HPP
#define PRINTRESULT_HPP
#include <iostream>
#include "rectangle.hpp"
#include "ellipse.hpp"
#include "circle.hpp"

namespace duhanina
{
  void outFigures(std::ostream& out, Shape** shapes, size_t shapeCount);
  double calcArea(Shape** shapes, size_t shapeCount);
  void printFiguresInfo(std::ostream& out, Shape** shapes, size_t shapeCount);
  void processScaling(Shape** shapes, size_t shapeCount, point_t point, double scalingFactor);
}

#endif
