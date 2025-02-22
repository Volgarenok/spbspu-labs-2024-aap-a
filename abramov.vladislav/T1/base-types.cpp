#include "base-types.hpp"
#include <cmath>

double abramov::getLength(const point_t &p1, const point_t &p2)
{
  return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

void abramov::changePointCoords(point_t &p, double dx, double dy)
{
  p.x += dx;
  p.y += dy;
}
