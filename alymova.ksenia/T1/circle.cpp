#include "circle.hpp"
#include <cmath>
#include <stdexcept>
constexpr double PII = std::acos(-1.0);
constexpr size_t angles_cnt = 73;
constexpr double angle_73 = 360.0 / angles_cnt / 2.0 * PII / 180.0;
alymova::Circle::Circle(point_t pos, double radius):
  pos_(pos),
  radius_(1.0),
  regular_()
{
  if (radius <= 0.0)
  {
    throw std::logic_error("Incorrect description circle");
  }
  radius_ = radius;
  point_t top = {pos_.x, pos_.y + radius_};
  double catheter = std::cos(angle_73) * radius_;
  double shift_x = std::sin(angle_73) * catheter;
  double shift_y = std::cos(angle_73) * catheter;
  point_t other = {pos_.x + shift_x, pos_.y + shift_y};
  regular_ = Regular{pos, top, other};
}
double alymova::Circle::getArea() const noexcept
{
  return regular_.getArea();
}
alymova::rectangle_t alymova::Circle::getFrameRect() const noexcept
{
  return regular_.getFrameRect();
}
void alymova::Circle::move(double shift_x, double shift_y) noexcept
{
  regular_.move(shift_x, shift_y);
}
void alymova::Circle::move(point_t point) noexcept
{
  regular_.move(point);
}
void alymova::Circle::unsafeScale(double ratio) noexcept
{
  regular_.unsafeScale(ratio);
}
alymova::Shape* alymova::Circle::clone() const
{
  Circle* circle = nullptr;
  try
  {
    circle = new Circle(pos_, radius_);
    Shape* shape = circle;
    return shape;
  }
  catch (const std::bad_alloc& e)
  {
    delete circle;
    throw;
  }
}
