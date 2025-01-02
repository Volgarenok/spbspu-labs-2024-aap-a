#ifndef MAKE_SHAPES_HPP
#define MAKE_SHAPES_HPP

#include <iostream>
#include <cstddef>
#include "shape.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "parallelogram.hpp"
#include "diamond.hpp"

namespace guseynov
{
  void clearShapes(guseynov::Shape **shp, size_t currentIndx);
  double getAreaSum(guseynov::Shape **shp, size_t Num);
  void printFrRectCords(std::ostream& out, guseynov::Shape **shp, size_t Num);
  void scaleAllRelativeTo(Shape **shp, size_t Num, guseynov::point_t p, double k);
  guseynov::Rectangle* makeRectangle(std::istream& in);
  guseynov::Square* makeSquare(std::istream& in);
  guseynov::Parallelogram* makeParallelogram(std::istream& in);
  guseynov::Diamond* makeDiamond(std::istream& in);
}

#endif
