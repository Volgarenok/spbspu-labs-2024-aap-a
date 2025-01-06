#include "base-types.hpp"
#include <cmath>

namespace abramov
{
  double getLength(point_t p1, point_t p2)
  {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
  }

  void changePointCoords(point_t &p, double dx, double dy)
  {
    p.x += dx;
    p.y += dy;
  }
}
