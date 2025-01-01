#include "ring.hpp"
#include <cmath>
#include <stdexcept>

tkach::Ring::Ring(const point_t& center, const double outer_radius, const double inner_radius):
  center_(center),
  outer_radius_(outer_radius),
  inner_radius_(inner_radius)
{
  if (outer_radius <= inner_radius)
  {
    throw std::logic_error("Outer radius is lesser than inner_radius or equal to it");
  }
  if (outer_radius <= 0 || inner_radius <=0)
  {
    throw std::logic_error("Incorrect radius");
  }
}

double tkach::Ring::getArea() const
{
  return std::acos(-1) * (outer_radius_ * outer_radius_ - inner_radius_ * inner_radius_);
}

tkach::rectangle_t tkach::Ring::getFrameRect() const
{
  double height = 2 * outer_radius_;
  double width = 2 * outer_radius_;
  double frame_rect_pos_x = center_.x;
  double frame_rect_pos_y = center_.y;
  return {width, height, frame_rect_pos_x, frame_rect_pos_y};
}

void tkach::Ring::move(const double add_to_x, const double add_to_y)
{
  addToPoint(center_, add_to_x, add_to_y);
}

void tkach::Ring::move(const point_t& point_to_move)
{
  center_ = point_to_move;
}

void tkach::Ring::scaleOneOfUniqueShapes(const double multiplier)
{
  outer_radius_ *= multiplier;
  inner_radius_ *= multiplier;
}
