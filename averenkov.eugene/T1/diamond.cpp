#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
#include <iostream>

averenkov::Diamond::Diamond(point_t a_, point_t b_, point_t c_)
  : widthR(0.0), heightR(0.0)
{
  buildRectangles(a_, b_, c_);
}

double averenkov::Diamond::getArea() const
{
  return widthR * 8 * heightR * 4;
}

averenkov::rectangle_t averenkov::Diamond::getFrameRect() const
{
  point_t center = { 0.0, 0.0 };
  double sumx = 0.0, sumy = 0.0;
  for (size_t i = 0; i < 40; ++i)
  {
    sumx += rectangles[i].getFrameRect().pos.x;
    sumy += rectangles[i].getFrameRect().pos.y;
  }
  center = { ( sumx / 40 ), ( sumy / 40 ) };
  double width = widthR * 8;
  double height = heightR * 8;
  return { width, height, center };
}

void averenkov::Diamond::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Scale factor must be positive.");
  }
  point_t center = this->getFrameRect().pos;
  double scale_width = this->getFrameRect().width * factor;
  double scale_height = this->getFrameRect().height * factor;
  point_t a = {center.x + scale_width, center.y};
  point_t b = {center.x, center.y + scale_height};
//std::cout << "Point a: " << a.x << ", " << a.y << std::endl;
//std::cout << "Point b: " << b.x << ", " << b.y << std::endl;
  for (size_t i = 0; i < 40; i++)
  {
    rectangles[i] = Rectangle({ 0.0, 0.0 }, { 0.0, 0.0 });
  }
  buildRectangles(center, a, b);
}

void averenkov::Diamond::move(point_t new_pos)
{
  point_t center = getFrameRect().pos;
  double dx = new_pos.x - center.x;
  double dy = new_pos.y - center.y;
  move(dx, dy);
}

void averenkov::Diamond::move(double dx, double dy)
{
  for (size_t i = 0; i < 40; ++i)
  {
    rectangles[i].move(dx, dy);
  }
}

void averenkov::Diamond::buildRectangles(const point_t a, const point_t b, const point_t c)
{
  double width = 0, height = 0;
  point_t center = { 0.0, 0.0 };
  if ((a.x == b.x && a.y == c.y) || (a.x == c.x && a.y == b.y))
  {
    width = std::abs(c.x - a.x) + std::abs(b.x - a.x);
    height = std::abs(c.y - a.y) + std::abs(b.y - a.y);
    center = a;
  }
  else if ((b.x == a.x && b.y == c.y) || (b.x == c.x && b.y == a.y))
  {
    width = std::abs(c.x - b.x) + std::abs(a.x - b.x);
    height = std::abs(c.y - b.y) + std::abs(a.y - b.y);
    center = b;
  }
  else if ((c.x == a.x && c.y == b.y) || (c.x == b.x && c.y == a.y))
  {
    width = std::abs(a.x - c.x) + std::abs(b.x - c.x);
    height = std::abs(a.y - c.y) + std::abs(b.y - c.y);
    center = c;
  }
  else
  {
    throw std::invalid_argument("Incorrect input");
  }
  if (width == 0 || height == 0)
  {
    throw std::invalid_argument("Incorrect input");
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
        if (index >= 40)
        {
          throw std::out_of_range("Too many rectangles for the array.");
        }
        double x_offset = x_dir * (rect_in_level - (3 - level) / 2.0) * widthR;
        point_t rect_a = {center.x + x_offset - widthR / 2, center.y + y_offset - heightR / 2};
        point_t rect_c = {rect_a.x + widthR, rect_a.y + heightR};
        rectangles[index] = Rectangle(rect_a, rect_c);
//std::cout << rectangles[index].getFrameRect().pos.y + rectangles[index].getFrameRect().height / 2 << "\n";
        index++;
      }
    }
  }

}
