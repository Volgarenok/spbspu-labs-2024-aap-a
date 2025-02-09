#include "circle.hpp"
#include <cmath>
#include <stdexcept>
constexpr double PII = std::acos(-1.0);
constexpr size_t angles_cnt = 73;
constexpr double angle_73 = 360.0 / angles_cnt / 2.0 * PII / 180.0;
alymova::Circle::Circle(const point_t& pos, double radius):
  regular_(setRegular(pos, radius))
{
  if (radius <= 0.0)
  {
    throw std::logic_error("Incorrect description circle");
  }
}
alymova::Circle::Circle(const Circle& other):
  regular_(other.regular_)
{}
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
void alymova::Circle::move(const point_t& point) noexcept
{
  regular_.move(point);
}
void alymova::Circle::unsafeScale(double ratio) noexcept
{
  regular_.unsafeScale(ratio);
}
alymova::Shape* alymova::Circle::clone() const
{
  return new Circle(*this);
}
alymova::Regular alymova::Circle::setRegular(const point_t& pos, double radius)
{
  double catheter = std::cos(angle_73) * radius;
  double shift_x = std::sin(angle_73) * catheter;
  double shift_y = std::cos(angle_73) * catheter;
  point_t top = {pos.x, pos.y + radius};
  point_t other = {pos.x + shift_x, pos.y + shift_y};
  return {pos, top, other};
}
