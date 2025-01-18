#ifndef SHAPEBREEDING_HPP
#define SHAPEBREEDING_HPP

#include <istream>
#include "concave.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "parallelogram.hpp"

namespace kushekbaev
{
  bool isTriangle(const point_t first, const point_t second, const point_t third);
  bool isPointInsideTriangle(const point_t first, const point_t second, const point_t third, const point_t final);
  point_t makeScale(std::istream& input);
}

#endif
