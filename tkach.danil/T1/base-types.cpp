#include "base-types.hpp"

double tkach::getCoordDistMultiplied(const double point1_coord, const double point2_coord, const double multiplier)
{
  return (point1_coord - point2_coord) * multiplier;
}

tkach::point_t tkach::getShiftedPointFromAnother(const point_t& first_point, const point_t& another_point, const double multiplier)
{
  return {another_point.x + getCoordDistMultiplied(first_point.x, another_point.x, multiplier), another_point.y
    + getCoordDistMultiplied(first_point.y, another_point.y, multiplier)};
}

void tkach::addToPoint(point_t& change_point, const double add_to_x, const double add_to_y)
{
  change_point.x += add_to_x;
  change_point.y += add_to_y;
}
