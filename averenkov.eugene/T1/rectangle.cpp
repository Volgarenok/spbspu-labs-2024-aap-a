#include "rectangle.hpp"
#include <iostream>
averenkov::Rectangle::Rectangle(averenkov::point_t a_, averenkov::point_t c_):
  a(a_),
  c(c_)
{
}


void averenkov::Rectangle::move(averenkov::point_t s)
{
  point_t center;
  center.x = (a.x + c.x) / 2;
  center.y = (a.y + c.y) / 2;
  a.x = s.x - (center.x - a.x);
  c.x = s.x + (c.x - center.x);
  a.y = s.y - (center.y - a.y);
  c.y = s.y + (c.y - center.y);
}

averenkov::rectangle_t averenkov::Rectangle::getFrameRect() const
{
  double width = c.x - a.x;
  double height = c.y - a.y;
  point_t pos;
  pos.x = (a.x + c.x) / 2;
  pos.y = (a.y + c.y) / 2;
  return { width, height, pos };
}


void averenkov::Rectangle::scale(double factor)
{
  if (factor <= 0)
  {
    throw "invalid scale";
  }
  point_t pos = Rectangle::getFrameRect().pos;
  a.x = pos.x - ((pos.x - a.x) * factor);
  a.y = pos.y - ((pos.y - a.y) * factor);
  c.x = ((c.x - pos.x) * factor) + pos.x;
  c.y = ((c.y - pos.y) * factor) + pos.y;
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

