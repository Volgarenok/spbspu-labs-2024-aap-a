#ifndef SHAPEBREEDING_HPP
#define SHAPEBREEDING_HPP

#include <istream>

namespace kushekbaev
{
  bool isTriangle(const point_t first, const point_t second, const point_t third);
  bool isPointInsideTriangle(const point_t first, const point_t second, const point_t third, const point_t final);
  point_t makeScale(std::istream& input);
}

#endif
