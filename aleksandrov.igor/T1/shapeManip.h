#ifndef SHAPEMANIP_H
#define SHAPEMANIP_H

#include <iosfwd>
#include <string>
#include "shape.hpp"
#include "rectangle.hpp"
#include "ellipse.hpp"
#include "circle.hpp"

namespace aleksandrov
{
  size_t getShapes(std::istream& input, Shape** shapes, double* params, size_t maxParams, bool& error);
  double getAreaSum(const Shape* const* shapes, size_t count);
  Shape* makeShape(const std::string& shapeName, double* params);
  size_t getShapeParams(std::istream& input, double* params, size_t maxParams);
  void scaleShapes(Shape** shapes, size_t count, double x, double y, double k);
  void printFrameRectCoords(std::ostream& output, const Shape* const* shapes, size_t count);
  void printFrameRectPoints(std::ostream& output, rectangle_t frameRect);
  void deleteShapes(Shape** shape);
}

#endif

