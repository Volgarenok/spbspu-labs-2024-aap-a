#ifndef SHAPEMANIP_H
#define SHAPEMANIP_H

#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "ellipse.hpp"
#include "circle.hpp"

namespace aleksandrov
{
  size_t getShapes(std::istream& input, Shape** shapes, bool& error);
  double getAreaSum(Shape** shapes, size_t count);
  void getScaleParams(std::istream& input, double& x, double& y, double& k);
  Rectangle* makeRectangle(std::istream& input);
  Ellipse* makeEllipse(std::istream& input);
  Circle* makeCircle(std::istream& input);
  void scaleShapes(Shape** shapes, size_t count, double x, double y, double k);
  void printFrameRectCoords(std::ostream& output, Shape** shape, size_t count);
  void deleteShapes(Shape** shape, size_t count);
}

#endif

