#ifndef SHAPEBREEDING_HPP
#define SHAPEBREEDING_HPP

#include <istream>

#include "rectangle.hpp"
#include "concave.hpp"

namespace kushekbaev
{
  bool isTriangle(point_t first, point_t second, point_t third);
  Rectangle* makeRectangle(std::istream& input);
  Concave* makeConcave(std::istream& input);
  point_t makeScale(std::istream& input);
}

#endif
