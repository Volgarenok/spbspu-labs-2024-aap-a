#include "ring.hpp"
#include <cmath>
#include <stdexcept>

tkach::Ring::Ring(const point_t& center, double outer_radius, double inner_radius):
  in_reg_(nullptr),
  out_reg_(nullptr)
{
   if (outer_radius <= inner_radius)
  {
    throw std::logic_error("Outer radius is lesser than inner_radius or equal to it");
  }
  if (outer_radius <= 0 || inner_radius <= 0)
  {
    throw std::logic_error("Incorrect radius");
  }
  const double step_in_angle = 2.0 * std::acos(-1.0) / 130.0;
  const double step_out_angle = 2.0 * std::acos(-1.0) / 170.0;
  point_t temp_point;
  temp_point.x = inner_radius * std::cos(step_in_angle) + center.x;
  temp_point.y = inner_radius * std::sin(step_in_angle) + center.y;
  point_t new_in_point = {(center.x + inner_radius + temp_point.x) / 2.0, (temp_point.y + center.y) / 2.0};
  temp_point.x = outer_radius * std::cos(step_out_angle) + center.x;
  temp_point.y = outer_radius * std::sin(step_out_angle) + center.y;
  point_t new_out_point = {(center.x + outer_radius + temp_point.x) / 2.0, (temp_point.y + center.y) / 2.0};
  try
  {
    in_reg_ = new tkach::Regular(center, {center.x + inner_radius, center.y}, new_in_point);
    out_reg_ = new tkach::Regular(center, {center.x + outer_radius, center.y}, new_out_point);
  }
  catch (const std::logic_error& e)
  {
    delete in_reg_;
    delete out_reg_;
    throw;
  }
  catch (const std::bad_alloc& e)
  {
    delete in_reg_;
    delete out_reg_;
    throw;
  }
}

tkach::Ring::~Ring()
{
  delete in_reg_;
  delete out_reg_;
}

double tkach::Ring::getArea() const
{
  return out_reg_->getArea() - in_reg_->getArea();
}

tkach::rectangle_t tkach::Ring::getFrameRect() const
{
  return out_reg_->getFrameRect();
}

void tkach::Ring::move(const double add_to_x, const double add_to_y)
{
  in_reg_->move(add_to_x, add_to_y);
  out_reg_->move(add_to_x, add_to_y);
}

tkach::Shape* tkach::Ring::clone() const
{
  return new Ring(*this);
}

void tkach::Ring::move(const point_t& point_to_move)
{
  in_reg_->move(point_to_move);
  out_reg_->move(point_to_move);
}

void tkach::Ring::scaleOneOfUniqueShapes(const double multiplier)
{
  in_reg_->scale(multiplier);
  out_reg_->scale(multiplier);
}
