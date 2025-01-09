#ifndef MAKESHAPE_HPP
#define MAKESHAPE_HPP
#include "rectangle.hpp"
#include "ellipse.hpp"
#include "diamond.hpp"
#include <iostream>

namespace averenkov
{
  void makeRectangle(Shape** shapes, size_t& shapeCount, std::istream& in, bool& errors);
  void makeDiamond(Shape** shapes, size_t& shapeCount, std::istream& in, bool& errors);
  void makeEllipse(Shape** shapes, size_t& shapeCount, std::istream& in, bool& errors);
}
#endif
