#include "base-types.hpp"

namespace kushekbaev
{
  void moveDelta(double dx, double dy, point_t point)
  {
    point.x += dx;
    point.y += dy;
  }

  void isoScaling(double V, point_t middle, point_t point)
  {
    point.x = middle.x + (point.x - middle.x) * V;
    point.y = middle.y + (point.y - middle.y) * V;
  }
}
