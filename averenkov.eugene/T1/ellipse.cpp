#include "ellipse.hpp"

averenkov::Ellipse::Ellipse(point_t center_, double radius_v_, double radius_h_):
  center(center_),
  radius_v(radius_v_),
  radius_h(radius_h_)
{
}

void averenkov::Ellipse::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::logic_error("invalid input");
  }
  radius_h *= factor;
  radius_v *= factor;
}

double averenkov::Ellipse::getArea() const
{
  return 3.1416 * radius_h * radius_v;
}

averenkov::rectangle_t averenkov::Ellipse::getFrameRect() const
{
  double width = radius_h * 2;
  double height = radius_v * 2;
  return { width, height, center };
}

void averenkov::Ellipse::move(point_t s)
{
  center = s;
}

void averenkov::Ellipse::move(double x_plus, double y_plus)
{
  center.x = center.x + x_plus;
  center.y = center.y + y_plus;
}
