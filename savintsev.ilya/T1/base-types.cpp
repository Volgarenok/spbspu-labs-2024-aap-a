#include "base-types.hpp"
#include <cmath>

double savintsev::getLength(point_t lhs, point_t rhs)
{
  return std::sqrt(std::pow((lhs.x - rhs.x), 2) + std::pow((lhs.y - rhs.y), 2));
}
