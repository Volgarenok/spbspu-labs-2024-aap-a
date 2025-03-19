#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <fstream>
#include "rectangle.hpp"
#include "concave.hpp"

namespace ivanova
{
  double vectorLength(point_t a, point_t b);
  void deleteShapes(Shape** shps, const size_t size);
  double getSumArea(Shape **shp, size_t size);
  void printFrameRect(Shape** shps, size_t size);
  void scale(Shape** shps, size_t size, double k);
}

#endif
