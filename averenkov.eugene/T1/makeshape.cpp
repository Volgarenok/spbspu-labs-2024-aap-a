#include "makeshape.hpp"
#include <iostream>

void averenkov::makeRectangle(averenkov::Shape** shapes, size_t& shapeCount, std::istream& input)
{
  point_t a, c;
    if (!(input >> a.x >> a.y >> c.x >> c.y) || a.x > c.x || a.y > c.x)
    {
      return;
    }
  Rectangle* rect = new Rectangle(a, c);
  shapes[shapeCount++] = rect;
  return;
}

void averenkov::makeDiamond(averenkov::Shape** shapes, size_t& shapeCount, std::istream& input)
{
  point_t a;
  point_t b;
  point_t c;
  try
  {
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
  }
  catch(...)
  {
    return;
  }
  Diamond* diam = new Diamond(a, b, c);
  shapes[shapeCount++] = diam;
  return;
}

void averenkov::makeEllipse(averenkov::Shape** shapes, size_t& shapeCount, std::istream& input)
{
  point_t center;
  double a, b;
  try
  {
    if (!(input >> center.x >> center.y >> a >> b) || a <= 0 || b <= 0)
    {
      throw std::invalid_argument("Invalid ELLIPSE");
    }
  }
  catch(...)
  {
    return;
  }
  Ellipse* ellip = new Ellipse(center, a, b);
  shapes[shapeCount++] = ellip;
  return;
}












