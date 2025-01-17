#include "rectangle.hpp"
#include <stdexcept>

averenkov::Rectangle::Rectangle():
  a_({0.0, 0.0}),
  c_({0.0, 0.0})
{
}

averenkov::Rectangle::Rectangle(point_t a, point_t c):
  a_(a),
  c_(c)
{
  if (a.x > c.x || a.y > c.y)
  {
    throw std::invalid_argument("Error in parameters");
  }
}

void averenkov::Rectangle::move(point_t s)
{
  point_t center;
  center.x = (a_.x + c_.x) / 2;
  center.y = (a_.y + c_.y) / 2;
  a_.x = s.x - (center.x - a_.x);
  c_.x = s.x + (c_.x - center.x);
  a_.y = s.y - (center.y - a_.y);
  c_.y = s.y + (c_.y - center.y);
}

averenkov::rectangle_t averenkov::Rectangle::getFrameRect() const
{
  double width = c_.x - a_.x;
  double height = c_.y - a_.y;
  point_t pos;
  pos.x = (a_.x + c_.x) / 2;
  pos.y = (a_.y + c_.y) / 2;
  return { width, height, pos };
}


void averenkov::Rectangle::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::logic_error("invalid scale");
  }
  point_t pos = Rectangle::getFrameRect().pos;
  a_.x = pos.x - ((pos.x - a_.x) * factor);
  a_.y = pos.y - ((pos.y - a_.y) * factor);
  c_.x = ((c_.x - pos.x) * factor) + pos.x;
  c_.y = ((c_.y - pos.y) * factor) + pos.y;
}

void averenkov::Rectangle::move(double x_plus, double y_plus)
{
  a_.x = a_.x + x_plus;
  c_.x = c_.x + x_plus;
  a_.y = a_.y + y_plus;
  c_.y = a_.y + y_plus;
}

double averenkov::Rectangle::getArea() const
{
  if ((c_.x - a_.x) * (c_.y - a_.y) < 0)
  {
    return -((c_.x - a_.x) * (c_.y - a_.y));
  }
  return (c_.x - a_.x) * (c_.y - a_.y);
}

averenkov::point_t averenkov::Rectangle::getLeftBottom() const
{
  return a_;
}
averenkov::point_t averenkov::Rectangle::getRightTop() const
{
  return c_;
}
