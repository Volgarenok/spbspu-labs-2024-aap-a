#include "makeshape.hpp"
#include <iostream>

averenkov::Rectangle* averenkov::makeRectangle(std::istream& input)
{
  point_t a, c;
  if (!(input >> a.x >> a.y >> c.x >> c.y) || a.x > c.x || a.y > c.x)
  {
    throw std::invalid_argument("Invalid RECTANGLE");
  }
  Rectangle* rect = new Rectangle(a, c);
  return rect;
}

averenkov::Diamond* averenkov::makeDiamond(std::istream& input)
{
  point_t a;
  point_t b;
  point_t c;
  if (!(input >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y))
  {
    throw std::invalid_argument("Invalid DIAMOND");
  }
  if (!((a.x == b.x && a.y == c.y) ||
    (a.x == c.x && a.y == b.y) ||
    (b.x == a.x && b.y == c.y) ||
    (b.x == c.x && b.y == a.y) ||
    (c.x == a.x && c.y == b.y) ||
    (c.x == b.x && c.y == a.y)))
  {
    throw std::invalid_argument("Invalid DIAMOND");
  }
  Diamond* diam = new Diamond(a, b, c);
  return diam;
}

averenkov::Ellipse* averenkov::makeEllipse(std::istream& input)
{
  point_t center;
  double a, b;
  if (!(input >> center.x >> center.y >> a >> b) || a <= 0 || b <= 0)
  {
    throw std::invalid_argument("Invalid ELLIPSE");
  }
  Ellipse* ellip = new Ellipse(center, a, b);
  return ellip;
}












