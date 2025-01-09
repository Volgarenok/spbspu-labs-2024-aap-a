#include "pointManip.hpp"
#include <cmath>
#include <stdexcept>

void gavrilova::move(point_t& p, double difX, double difY) noexcept
{
  p.x += difX;
  p.y += difY;
}
double gavrilova::getDistance(point_t& p, gavrilova::point_t other) noexcept
{
  return std::sqrt(std::pow(p.x - other.x, 2) + std::pow(p.y - other.y, 2));
}
void gavrilova::scaleDistance(point_t& p, gavrilova::point_t other, double k)
{
  p.x = other.x - (other.x - p.x) * k;
  p.y = other.y - (other.y - p.y) * k;
}
