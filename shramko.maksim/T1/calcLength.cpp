#include "calcLength.hpp"

double shramko::calcLength(const point_t p1, const point_t p2)
{
  return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}