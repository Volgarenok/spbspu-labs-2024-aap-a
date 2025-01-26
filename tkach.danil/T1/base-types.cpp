#include "base-types.hpp"

double tkach::getCoordDistMultiplied(const double point1_coord, const double point2_coord, const double multiplier)
{
  return (point1_coord - point2_coord) * multiplier;
}

tkach::point_t tkach::getShiftedPointFromAnother(const point_t& first, const point_t& other, const double multiplier)
{
  return {other.x + getCoordDistMultiplied(first.x, other.x, multiplier), other.y + getCoordDistMultiplied(first.y, other.y, multiplier)};
}

void tkach::addToPoint(point_t& change_point, const double add_to_x, const double add_to_y)
{
  change_point.x += add_to_x;
  change_point.y += add_to_y;
}
