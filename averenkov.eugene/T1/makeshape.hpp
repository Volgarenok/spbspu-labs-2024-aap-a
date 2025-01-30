#ifndef MAKESHAPE_HPP
#define MAKESHAPE_HPP
#include <iostream>
#include "rectangle.hpp"
#include "ellipse.hpp"
#include "diamond.hpp"

namespace averenkov
{
  void makeRectangle(Shape** shapes, size_t& shapeCount, std::istream& in, bool& errors);
  void makeDiamond(Shape** shapes, size_t& shapeCount, std::istream& in, bool& errors);
  void makeEllipse(Shape** shapes, size_t& shapeCount, std::istream& in, bool& errors);
  void makeScale(double& factor, point_t& scale_center, std::istream& input);
}

#endif
