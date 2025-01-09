#ifndef SHAPEMANIP_H
#define SHAPEMANIP_H

#include <iostream>
#include <string>
#include "shape.hpp"
#include "rectangle.hpp"
#include "ellipse.hpp"
#include "circle.hpp"

namespace aleksandrov
{
  size_t getShapes(std::istream& input, Shape** shapes, bool& error);
  double getAreaSum(Shape** shapes, size_t count);
  Shape* makeShape(const std::string& shapeName, double* params);
  size_t getParamsCount(const std::string& command);
  std::istream& getShapeParams(std::istream& input, double* params, size_t paramsCount);
  void scaleShapes(Shape** shapes, size_t count, double x, double y, double k);
  void printFrameRectCoords(std::ostream& output, Shape** shape, size_t count);
  void deleteShapes(Shape** shape);
}

#endif

