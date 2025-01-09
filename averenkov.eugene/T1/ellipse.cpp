#include "ellipse.hpp"
#include <stdexcept>

averenkov::Ellipse::Ellipse(point_t center, double radius_v, double radius_h):
  center_(center),
  radius_v_(radius_v),
  radius_h_(radius_h)
{
}

void averenkov::Ellipse::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::logic_error("invalid input");
  }
  radius_h_ *= factor;
  radius_v_ *= factor;
}

double averenkov::Ellipse::getArea() const
{
  return 3.1416 * radius_h_ * radius_v_;
}

averenkov::rectangle_t averenkov::Ellipse::getFrameRect() const
{
  double width = radius_h_ * 2;
  double height = radius_v_ * 2;
  return { width, height, center_ };
}

void averenkov::Ellipse::move(point_t s)
{
  center_ = s;
}

void averenkov::Ellipse::move(double x_plus, double y_plus)
{
  center_.x = center_.x + x_plus;
  center_.y = center_.y + y_plus;
}
