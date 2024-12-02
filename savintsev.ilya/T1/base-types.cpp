#include "base-types.hpp"
#include <cmath>

double savintsev::getLength(point_t lhs, point_t rhs)
{
  return std::sqrt(std::pow((lhs.x - rhs.x), 2) + std::pow((lhs.y - rhs.y), 2));
}

bool savintsev::isPointInTriangle(point_t t1, point_t t2, point_t t3, point_t p)
{
  int part1 = (t1.x - p.x) * (t2.y - t1.y) - (t2.x - t1.x) * (t1.y - p.y);
  int part2 = (t2.x - p.x) * (t3.y - t2.y) - (t3.x - t2.x) * (t2.y - p.y);
  int part3 = (t3.x - p.x) * (t1.y - t3.y) - (t1.x - t3.x) * (t3.y - p.y);
  if (part1 > 0 && part2 > 0 && part3 > 0)
  {
    return true;
  }
  else if (part1 < 0 && part2 < 0 && part3 < 0)
  {
    return true;
  }
  return false;
}
