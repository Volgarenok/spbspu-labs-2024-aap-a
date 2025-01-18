#include "ring.hpp"
#include <cmath>
#include <stdexcept>

tkach::Regular tkach::Ring::getReg(size_t sides_amount, const point_t& center, double radius)
{
  const double step_in_angle = 2.0 * std::acos(-1.0) / sides_amount;
  point_t temp_point= {radius * std::cos(step_in_angle) + center.x, radius * std::sin(step_in_angle) + center.y};
  point_t new_point = {(center.x + radius + temp_point.x) / 2.0, (temp_point.y + center.y) / 2.0};
  return {center, {center.x + radius, center.y}, new_point};
}

tkach::Ring::Ring(const point_t& center, double outer_radius, double inner_radius):
  in_reg_(getReg(130, center, inner_radius)),
  out_reg_(getReg(170, center, outer_radius))
{
  if (outer_radius <= inner_radius || outer_radius <= 0 || inner_radius <= 0)
  {
    throw std::logic_error("Incorrect radius");
  }
}

double tkach::Ring::getArea() const
{
  return out_reg_.getArea() - in_reg_.getArea();
}

tkach::rectangle_t tkach::Ring::getFrameRect() const
{
  return out_reg_.getFrameRect();
}

void tkach::Ring::move(const double add_to_x, const double add_to_y)
{
  in_reg_.move(add_to_x, add_to_y);
  out_reg_.move(add_to_x, add_to_y);
}

tkach::Shape* tkach::Ring::clone() const
{
  return new Ring(*this);
}

void tkach::Ring::move(const point_t& point_to_move)
{
  in_reg_.move(point_to_move);
  out_reg_.move(point_to_move);
}

void tkach::Ring::doUnsafeScale(const double multiplier)
{
  in_reg_.doUnsafeScale(multiplier);
  out_reg_.doUnsafeScale(multiplier);
}
