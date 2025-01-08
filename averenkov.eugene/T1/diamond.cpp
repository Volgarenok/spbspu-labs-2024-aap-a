#include "diamond.hpp"
#include <cmath>
#include <iostream>
averenkov::Diamond::Diamond(point_t a_, point_t b_, point_t c_):
  rectangles(nullptr), widthR(1.0), heightR(1.0)
{
  rectangles = buildRectangles(a_, b_, c_);
}

double averenkov::Diamond::getArea() const
{
//  double p = (averenkov::getLine(a, b) + averenkov::getLine(b, c) + averenkov::getLine(a, c)) / 2;
//  return std::sqrt(p * (p - averenkov::getLine(a, b)) * (p - averenkov::getLine(b, c)) * (p - averenkov::getLine(a, c))) * 4;
  return rectangles[1]->getArea() * 40;
}

averenkov::rectangle_t averenkov::Diamond::getFrameRect() const
{
  double x_sum, y_sum;
  for (size_t i = 0; i < 40; i++)
  {
    x_sum += rectangles[i]->getFrameRect().pos.x;
    y_sum += rectangles[i]->getFrameRect().pos.y;
  }
  point_t center = { x_sum / 40, y_sum / 40 };
  double width = widthR * 8;
  double height = heightR * 8;
  return { width, height, center };
}

void averenkov::Diamond::scale(double factor)
{
  if (factor <= 0)
  {
    throw "invalid scale";
  }
  for (size_t i; i < 40; i++)
  {
    rectangles[i]->scale(factor);
  }
}

void averenkov::Diamond::move(point_t s)
{
  point_t center = this->getFrameRect().pos;
  double moveX = s.x - center.x;
  double moveY = s.y - center.y;
  for (size_t i; i < 40; i++)
  {
    rectangles[i]->move(moveX, moveY);
  }
}

void averenkov::Diamond::move(double x_plus, double y_plus)
{
  for(size_t i = 0; i < 40; i++)
  {
    rectangles[i]->move(x_plus, y_plus);
  }
}
averenkov::Rectangle** averenkov::Diamond::buildRectangles(const point_t a, const point_t b, const point_t c)
{
  Rectangle** rectangles = new Rectangle*[40];
  double width = 0, height = 0;
  point_t center = { 0.0, 0.0 };
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
  if (width == 0 || height == 0)
  {
    throw std::runtime_error("Invalid dimensions for rectangles");
  }
  widthR = width / 8;
  heightR = height / 8;
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
