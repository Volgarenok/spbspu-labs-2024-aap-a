#include "base-types.hpp"

double tkach::getCoordDistMultiplied(const double point1_coord, const double point2_coord, const double multiplier)
{
  return (point1_coord - point2_coord) * multiplier;
}

tkach::point_t tkach::getShiftedPointFromAnother(const point_t& first, const point_t& other, const double multiplier)
{
  double dist_x = getCoordDistMultiplied(first.x, other.x, multiplier);
  double dist_y = getCoordDistMultiplied(first.y, other.y, multiplier);
  return {other.x + dist_x, other.y + dist_y};
}

void tkach::addToPoint(point_t& change_point, const double add_to_x, const double add_to_y)
{
  change_point.x += add_to_x;
  change_point.y += add_to_y;
}
