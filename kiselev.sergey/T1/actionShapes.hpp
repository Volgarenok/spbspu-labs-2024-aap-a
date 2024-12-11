#ifndef ACTIONSHAPES_HPP
#define ACTIONSHAPES_HPP
#include "base-types.hpp"
#include "shape.hpp"
namespace kiselev
{
  double getSumArea(kiselev::Shape** shapes, size_t countShape);
  void scaleForShapes(kiselev::Shape** shapes, size_t countShape, kiselev::point_t scale, double ratio);
  void printCoordinatesRect(kiselev::Shape** shapes, size_t countShape);
}
#endif
