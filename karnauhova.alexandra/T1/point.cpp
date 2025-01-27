#include "point.hpp"
#include <cmath>
double karnauhova::getDistance(point_t a, point_t b)
{
  return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

bool karnauhova::isEqual(point_t a, point_t b)
{
  if ((a.x == b.x) && (a.y == b.y))
  {
    return true;
  }
  return false;
}
