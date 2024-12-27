#include "shape.hpp"
#include <stdexcept>

void tkach::Shape::scale(double multiplier)
{
  if (multiplier <= 0)
  {
    throw std::logic_error("dfs");
  }
  scaleShape(multiplier);
}

void tkach::addToPoint(point_t& change_point, const double add_to_x, const double add_to_y)
{
  change_point.x += add_to_x;
  change_point.y += add_to_y;
}
