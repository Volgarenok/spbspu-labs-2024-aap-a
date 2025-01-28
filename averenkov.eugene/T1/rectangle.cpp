#include "rectangle.hpp"
#include <stdexcept>
#include "rectanglepoints.hpp"
#include "base-types.hpp"
#include "getline.hpp"

averenkov::Rectangle::Rectangle(const point_t& a, const point_t& c):
  a_(a),
  c_(c)
{
  if (a.x > c.x || a.y > c.y)
  {
    throw std::invalid_argument("Error in parameters");
  }
}

void averenkov::Rectangle::move(const point_t& s)
{
  double dx = s.x - (getFrameRect().width / 2) - a_.x;
  double dy = s.y - (getFrameRect().height / 2) - a_.y;
  move(dx, dy);
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

void averenkov::Rectangle::move(double dx, double dy)
{
  a_.x = a_.x + dx;
  c_.x = c_.x + dx;
  a_.y = a_.y + dy;
  c_.y = c_.y + dy;
}

double averenkov::Rectangle::getArea() const
{
  return (c_.x - a_.x) * (c_.y - a_.y);
}
