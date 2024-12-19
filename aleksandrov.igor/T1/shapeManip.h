#ifndef SHAPEMANIP_H
#define SHAPEMANIP_H

#include "shape.hpp"
#include "rectangle.hpp"
#include "ellipse.hpp"
#include "circle.hpp"
#include <string>

namespace aleksandrov
{
  Rectangle* makeRectangle(const std::string rectangleParams, bool& error);
  Ellipse* makeEllipse(const std::string ellipseParams, bool& error);
  Circle* makeCircle(const std::string circleParams, bool& error);
  Shape* makeShape(const std::string shapeDescription, bool& error);
  void doScale(Shape** shapes, size_t count, double& x, double& y, double& k, double& sum);
  void printFrameRectCoords(Shape** shape, size_t count);
  void deleteShapes(Shape** shape, size_t count);
}

#endif

