#ifndef ACTIONSHAPES_HPP
#define ACTIONSHAPES_HPP
#include <ostream>
#include "base-types.hpp"
#include "shape.hpp"
namespace kiselev
{
  double getSumArea(kiselev::Shape** shapes, size_t countShape);
  void scaleForShapes(kiselev::Shape** shapes, size_t countShape, kiselev::point_t scale, double ratio);
  void printCoordinatesRect(std::ostream& output, kiselev::Shape** shapes, size_t countShape);
}
#endif
