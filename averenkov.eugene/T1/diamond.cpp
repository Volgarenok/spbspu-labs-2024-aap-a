#include "diamond.hpp"
#include <cmath>
#include <iostream>
averenkov::Diamond::Diamond(averenkov::point_t a_, averenkov::point_t b_, averenkov::point_t c_) : a(a_), b(b_), c(c_)
{
}

double averenkov::Diamond::getArea() const
{
  double p = (averenkov::getLine(a, b) + averenkov::getLine(b, c) + averenkov::getLine(a, c)) / 2;
  return std::sqrt(p * (p - averenkov::getLine(a, b)) * (p - averenkov::getLine(b, c)) * (p - averenkov::getLine(a, c))) * 4;
}

averenkov::rectangle_t averenkov::Diamond::getFrameRect() const
{
  double width, height;
  if ((a.x == b.x && a.y == c.y) || (a.x == c.x && a.y == b.y))
  {
    width = (c.x - a.x + b.x - a.x) * 2;
    height = (c.y - a.y + b.y - a.y) * 2;
    if (width < 0)
    {
      width = width - width - width;
    }
    if (height < 0)
    {
      height = height - height - height;
    }
    return { width, height, a };
  }
  if ((b.x == a.x && b.y == c.y) || (b.x == c.x && b.y == a.y))
  {
    width = (c.x - b.x + a.x - b.x) * 2;
    height = (c.y - b.y + a.y - b.y) * 2;
    if (width < 0)
    {
      width = width - width - width;
    }
    if (height < 0)
    {
      height = height - height - height;
    }
    return { width, height, b };
  }
  if ((c.x == a.x && c.y == b.y) || (c.x == b.x && c.y == a.y))
  {
    width = (a.x - c.x + b.x - c.x) * 2;
    height = (a.y - c.y + b.y - c.y) * 2;
    if (width < 0)
    {
      width = width - width - width;
    }
    if (height < 0)
    {
      height = height - height - height;
    }
    return { width, height, c };
  }
  return { 0.0, 0.0 };
}

void averenkov::Diamond::scale(double factor)
{
  point_t center = getFrameRect().pos;
  a.x = center.x + (a.x - center.x) * factor;
  a.y = center.y + (a.y - center.y) * factor;
  b.x = center.x + (b.x - center.x) * factor;
  b.y = center.y + (b.y - center.y) * factor;
  c.x = center.x + (c.x - center.x) * factor;
  c.y = center.y + (c.y - center.y) * factor;
}

void averenkov::Diamond::move(point_t s)
{
  if ((a.x == b.x && a.y == c.y) || (a.x == c.x && a.y == b.y))
  {
    b.x = b.x - a.x + s.x;
    b.y = b.y - a.y + s.y;
    c.x = c.x - a.x + s.x;
    c.y = c.y - a.y + s.y;
    a = s;
  }
  else if ((b.x == a.x && b.y == c.y) || (b.x == c.x && b.y == a.y))
  {
    a.x = a.x - b.x + s.x;
    a.y = a.y - b.y + s.y;
    c.x = c.x - b.x + s.x;
    c.y = c.y - b.y + s.y;
    b = s;
  }
  else if ((c.x == a.x && c.y == b.y) || (c.x == b.x && c.y == a.y))
  {
    a.x = a.x - c.x + s.x;
    a.y = a.y - c.y + s.y;
    b.x = b.x - c.x + s.x;
    b.y = b.y - c.y + s.y;
    c = s;
  }
}

void averenkov::Diamond::move(double x_plus, double y_plus)
{
  a.x += x_plus;
  b.x += x_plus;
  c.x += x_plus;
  a.y += y_plus;
  b.y += y_plus;
  c.y += y_plus;
}
