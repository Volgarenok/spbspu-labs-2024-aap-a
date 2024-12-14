#include "diamond.hpp"
#include <cmath>

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
  if ((a.x == b.x && a.y == c.y) || (a.x == c.x && a.y == b.y))
  {
    return { (c.x - a.x + b.x - a.x) * 2, (c.y - a.y + b.y - a.y) * 2, a };
  }
  if ((b.x == a.x && b.y == c.y) || (b.x == c.x && b.y == a.y))
  {
    return { (c.x - b.x + a.x - b.x) * 2, (c.y - b.y + a.y - b.y) * 2, b };
  }
  if ((c.x == a.x && c.y == b.y) || (c.x == b.x && c.y == a.y))
  {
    return { (a.x - c.x + b.x - c.x) * 2, (a.y - c.y + b.y - c.y) * 2, c };
  }
  return { 0.0, 0.0 };
}

void averenkov::Diamond::scale(double factor)
{
  if ((a.x == b.x && a.y == c.y) || (a.x == c.x && a.y == b.y))
  {
    if (c.x == a.x)
    {
      c.y = (c.y - a.y) * factor + a.y;
      b.x = (b.x - a.x) * factor + a.x;
    }
    if (b.x == a.x)
    {
      b.y = (b.y - a.y) * factor + a.y;
      c.x = (c.x - a.x) * factor + a.x;
    }
  }
  if ((b.x == a.x && b.y == c.y) || (b.x == c.x && b.y == a.y))
  {
    if (b.x == a.x)
    {
      a.y = (a.y - b.y) * factor + b.y;
      c.x = (c.x - b.x) * factor + b.x;
    }
    if (b.x == c.x)
    {
      a.y = (a.y - b.y) * factor + b.y;
      c.x = (c.x - b.x) * factor + b.x;
    }
  }
  if ((c.x == a.x && c.y == b.y) || (c.x == b.x && c.y == a.y))
  {
    if (c.x == a.x)
    {
      a.y = (c.y - a.y) * factor + a.y;
      b.x = (c.x - b.x) * factor + b.x;
    }
  }
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
  if ((b.x == a.x && b.y == c.y) || (b.x == c.x && b.y == a.y))
  {
    a.x = a.x - b.x + s.x;
    a.y = a.y - b.y + s.y;
    c.x = c.x - b.x + s.x;
    c.y = c.y - b.y + s.y;
    b = s;
  }
  if ((c.x == a.x && c.y == b.y) || (c.x == b.x && c.y == a.y))
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
