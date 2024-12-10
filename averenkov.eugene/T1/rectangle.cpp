#include "rectangle.hpp"

averenkov::Rectangle::Rectangle(averenkov::point_t a_, averenkov::point_t c_) : a(a_), c(c_)
{
}

void averenkov::Rectangle::scale(averenkov::point_t s, double factor)
{
  a.x = (a.x - s.x) * factor + s.x;
  a.y = (a.y - s.y) * factor + s.y;
  c.x = (c.x - s.x) * factor + s.x;
  c.y = (c.y - s.y) * factor + s.y;
}

void averenkov::Rectangle::move(averenkov::point_t s)
{
  averenkov::point_t center;
  center.x = (a.x + c.x) / 2;
  center.y = (a.y + c.y) / 2;
  a.x = s.x - (center.x - a.x);
  c.x = s.x + (c.x - center.x);
  a.y = s.y - (center.y - a.y);
  c.y = s.y - (c.y - center.y);
}

averenkov::rectangle_t averenkov::Rectangle::getFrameRect() const
{
  double width = c.x - a.x;
  double height = c.y - a.y;
  averenkov::point_t pos;
  pos.x = (a.x + c.x) / 2;
  pos.y = (a.y + c.y) / 2;
  return { width, height, pos };
}

void averenkov::Rectangle::move(double x_plus, double y_plus)
{
  a.x = a.x + x_plus;
  c.x = c.x + x_plus;
  a.y = a.y + y_plus;
  c.y = a.y + y_plus;
}

double averenkov::Rectangle::getArea() const
{
  return (c.x - a.x) * (c.y - a.y);
}

