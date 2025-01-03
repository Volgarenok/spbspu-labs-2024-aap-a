#include "diamond.hpp"
#include <cmath>
#include <iostream>
averenkov::Diamond::Diamond(point_t a_, point_t b_, point_t c_):
  a(a_),
  b(b_),
  c(c_)
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
  point_t center;
  if ((a.x == b.x && a.y == c.y) || (a.x == c.x && a.y == b.y))
  {
    width = (c.x - a.x + b.x - a.x) * 2;
    height = (c.y - a.y + b.y - a.y) * 2;
    center = a;
  }
  if ((b.x == a.x && b.y == c.y) || (b.x == c.x && b.y == a.y))
  {
    width = (c.x - b.x + a.x - b.x) * 2;
    height = (c.y - b.y + a.y - b.y) * 2;
    center = b;
  }
  if ((c.x == a.x && c.y == b.y) || (c.x == b.x && c.y == a.y))
  {
    width = (a.x - c.x + b.x - c.x) * 2;
    height = (a.y - c.y + b.y - c.y) * 2;
    center = c;
  }
  if (width < 0)
  {
    width = -width;
  }
  if (height < 0)
  {
    height = -height;
  }
  return { width, height, center };
}

void averenkov::Diamond::scale(double factor)
{
  if (factor <= 0)
  {
    throw "invalid scale";
  }
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
  point_t cen;
  if (this->getFrameRect().pos.x == a.x && this->getFrameRect().pos.y == a.y)
  {
    cen = a;
  }
  if (this->getFrameRect().pos.x == b.x && this->getFrameRect().pos.y == b.y)
  {
    cen = b;
  }
  if (this->getFrameRect().pos.x == c.x && this->getFrameRect().pos.y == c.y)
  {
    cen = c;
  }
  a.x = a.x - cen.x + s.x;
  a.y = a.y - cen.y + s.y;
  b.x = b.x - cen.x + s.x;
  b.y = b.y - cen.y + s.y;
  c.x = c.x - cen.x + s.x;
  c.y = c.y - cen.y + s.y;
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
averenkov::Rectangle** averenkov::Diamond::buildRectangles()
{
  Rectangle** rectangles = new Rectangle*[40];
  point_t center = this->getFrameRect().pos;
  double widthR = this->getFrameRect().width / 8;
  double heightR = this->getFrameRect().height / 8;
  size_t index = 0;
  for (size_t quadrant = 0; quadrant < 4; ++quadrant)
  {
    double x_dir = (quadrant % 2 == 0) ? -1 : 1;
    double y_dir = (quadrant < 2) ? -1 : 1;
    for (size_t level = 0; level < 4; ++level)
    {
      double y_offset = y_dir * (level * heightR);
      for (size_t rect_in_level = 0; rect_in_level < (4 - level); ++rect_in_level)
      {
        double x_offset = x_dir * (rect_in_level - (3 - level) / 2.0) * widthR;
        point_t rect_a = { center.x + x_offset - widthR / 2, center.y + y_offset - heightR / 2 };
        point_t rect_c = { rect_a.x + widthR, rect_a.y + heightR };
        rectangles[index] = new averenkov::Rectangle(rect_a, rect_c);
        ++index;
      }
    }
  }
  return rectangles;
}
