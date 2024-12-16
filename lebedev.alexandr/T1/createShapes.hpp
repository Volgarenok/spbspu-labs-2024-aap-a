#ifndef CREATESHAPES_HPP
#define CREATESHAPES_HPP
#include <istream>
#include "rectangle.hpp"
#include "diamond.hpp"
#include "concave.hpp"

namespace lebedev
{
  point_t createScalePoint(std::istream& input);
  Rectangle* createRectangle(std::istream& input);
  Diamond* createDiamond(std::istream& input);
  Concave* createConcave(std::istream& input);
  bool isTriangle(point_t p1, point_t p2, point_t p3);
  bool isPointInsideTriangle(point_t p1, point_t p2, point_t p3, point_t p4);
}
#endif
