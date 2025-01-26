#ifndef MOVINGPOINT_HPP
#define MOVINGPOINT_HPP
#include "base-types.hpp"

namespace duhanina
{
  point_t calculateOffset(const point_t& currentPos, const point_t& newPos);
  void movePoint(point_t& pos, double dx, double dy);
  point_t scalePoint(const point_t& point, const point_t& origin, double k);
}

#endif
