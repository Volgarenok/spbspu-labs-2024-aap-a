#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"

namespace
{
  averenkov::point_t scalePoint(const averenkov::point_t& point, const averenkov::point_t& pos, double factor)
  {
    return { pos.x + (point.x - pos.x) * factor, pos.y + (point.y - pos.y) * factor };
  }
}

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
  double x = (a_.x + c_.x) / 2;
  double y = (a_.y + c_.y) / 2;
  point_t pos = { x, y };
  return { width, height, pos };
}


void averenkov::Rectangle::scaleNonChecked(double factor)
{
  point_t pos = getFrameRect().pos;
  a_ = scalePoint(a_, pos, factor);
  c_ = scalePoint(c_, pos, factor);
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
