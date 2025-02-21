#include "pointManip.hpp"
#include <cmath>

void gavrilova::movePoint(point_t& p, double difX, double difY) noexcept
{
  p.x += difX;
  p.y += difY;
}
double gavrilova::getDistance(const point_t& p, const point_t& other) noexcept
{
  return std::sqrt(std::pow(p.x - other.x, 2) + std::pow(p.y - other.y, 2));
}
void gavrilova::scaleDistance(point_t& p, point_t& other, double k)
{
  p.x = other.x - (other.x - p.x) * k;
  p.y = other.y - (other.y - p.y) * k;
}
