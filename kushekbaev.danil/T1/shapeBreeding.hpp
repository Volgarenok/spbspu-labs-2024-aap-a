#ifndef SHAPEBREEDING_HPP
#define SHAPEBREEDING_HPP

#include <istream>
#include "base-types.hpp"

namespace kushekbaev
{
  namespace details
  {
    bool isTriangle(const point_t first, const point_t second, const point_t third);
    bool isPointInsideTriangle(const point_t first, const point_t second, const point_t third, const point_t last);
  }
}

#endif
