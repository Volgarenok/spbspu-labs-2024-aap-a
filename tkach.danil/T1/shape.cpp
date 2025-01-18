#include "shape.hpp"
#include <stdexcept>

void tkach::Shape::scale(double multiplier)
{
  if (multiplier <= 0)
  {
    throw std::logic_error("Error: not positive coef");
  }
  doUnsafeScale(multiplier);
}

tkach::point_t tkach::changePointToAnotherPlusAdd(const point_t& first_point, const point_t& another_point, const double multiplier)
{
  return {another_point.x + (first_point.x - another_point.x) * multiplier, another_point.y
    + (first_point.y - another_point.y) * multiplier};
}

void tkach::addToPoint(point_t& change_point, const double add_to_x, const double add_to_y)
{
  change_point.x += add_to_x;
  change_point.y += add_to_y;
}
