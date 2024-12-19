#ifndef MAKE_SHAPES_HPP
#define MAKE_SHAPES_HPP

#include <iostream>
#include <cstddef>
#include "shape.hpp"

namespace guseynov
{
  void clearShapes(guseynov::Shape **shp, size_t currentIndx);
  double getAreaSum(guseynov::Shape **shp, size_t Num);
  void printFrRectCords(std::ostream & out, guseynov::Shape **shp, size_t Num);
  void scaleAllRelativeTo(Shape **shp, size_t Num, guseynov::point_t p, double k);
  size_t makeShape(char *line, guseynov::Shape **shp, size_t sch, guseynov::point_t & p, double & k);
}

#endif
