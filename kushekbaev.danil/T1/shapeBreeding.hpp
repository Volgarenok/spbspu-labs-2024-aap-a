#ifndef SHAPEBREEDING_HPP
#define SHAPEBREEDING_HPP

#include <istream>

#include "rectangle.hpp"
#include "concave.hpp"
#include "parallelogram.hpp"
#include "diamond.hpp"

namespace kushekbaev
{
  bool parallelX(const point_t first, const point_t second);
  bool isTriangle(const point_t first, const point_t second, const point_t third);
  bool isPointInsideTriangle(point_t first, point_t second, point_t third, point_t final);
  Rectangle* makeRectangle(std::istream& input);
  Concave* makeConcave(std::istream& input);
  Parallelogram* makeParallelogram(std::istream& input);
  Diamond* makeDiamond(std::istream& input);
  point_t makeScale(std::istream& input);
}

#endif
