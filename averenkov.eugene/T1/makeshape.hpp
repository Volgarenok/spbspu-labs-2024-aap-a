#ifndef MAKESHAPE_HPP
#define MAKESHAPE_HPP
#include "rectangle.hpp"
#include "ellipse.hpp"
#include "diamond.hpp"
#include <iostream>

namespace averenkov
{
  void makeRectangle(Shape** shapes, size_t& shapeCount, std::istream& in);
  void makeDiamond(Shape** shapes, size_t& shapeCount, std::istream& in);
  void makeEllipse(Shape** shapes, size_t& shapeCount, std::istream& in);
}
#endif
