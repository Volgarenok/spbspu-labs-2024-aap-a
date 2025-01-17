#include "diamond.hpp"
#include <cmath>
#include <stdexcept>

averenkov::Diamond::Diamond(point_t a, point_t b, point_t c)
  : widthR_(0.0), heightR_(0.0), sumx_(0.0), sumy_(0.0)
{
  if (!((a.x == b.x && a.y == c.y) ||
    (a.x == c.x && a.y == b.y) ||
    (b.x == a.x && b.y == c.y) ||
    (b.x == c.x && b.y == a.y) ||
    (c.x == a.x && c.y == b.y) ||
    (c.x == b.x && c.y == a.y)))
  {
    throw std::invalid_argument("Error in parameters");
  }
  buildRectangles(a, b, c);
}

double averenkov::Diamond::getArea() const
{
  return widthR_ * 8 * heightR_ * 4;
}

averenkov::rectangle_t averenkov::Diamond::getFrameRect() const
{
  point_t center = { 0.0, 0.0 };
  center = { ( sumx_ / 40 ), ( sumy_ / 40 ) };
  double width = widthR_ * 8;
  double height = heightR_ * 8;
  return { width, height, center };
}

void averenkov::Diamond::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Scale factor must be positive.");
  }
  point_t center = this->getFrameRect().pos;
  double scale_width = this->getFrameRect().width / 2 * factor;
  double scale_height = this->getFrameRect().height / 2 * factor;
  point_t a = {center.x + scale_width, center.y};
  point_t b = {center.x, center.y + scale_height};
  buildRectangles(center, a, b);
}

void averenkov::Diamond::move(point_t new_pos)
{
  point_t center = getFrameRect().pos;
  double dx = new_pos.x - center.x;
  double dy = new_pos.y - center.y;
  move(dx, dy);
  sumx_ += dx * 40;
  sumy_ += dy * 40;
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
  sumy_ = 0;
  if ((a.x == b.x && a.y == c.y) || (a.x == c.x && a.y == b.y))
  {
    width = std::abs(c.x - a.x) * 2 + std::abs(b.x - a.x) * 2;
    height = std::abs(c.y - a.y) * 2 + std::abs(b.y - a.y) * 2;
    center = a;
  }
  else if ((b.x == a.x && b.y == c.y) || (b.x == c.x && b.y == a.y))
  {
    width = std::abs(c.x - b.x) * 2 + std::abs(a.x - b.x) * 2;
    height = std::abs(c.y - b.y) * 2 + std::abs(a.y - b.y) * 2;
    center = b;
  }
  else if ((c.x == a.x && c.y == b.y) || (c.x == b.x && c.y == a.y))
  {
    width = std::abs(a.x - c.x) * 2 + std::abs(b.x - c.x) * 2;
    height = std::abs(a.y - c.y) * 2 + std::abs(b.y - c.y) * 2;
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

  widthR_ = width / 8;
  heightR_ = height / 8;
  size_t index = 0;
  sumx_ = 0.0;
  sumy_ = 0.0;
  for (size_t quadrant = 0; quadrant < 4; ++quadrant)
  {
    double x_dir = (quadrant % 2 == 0) ? -1 : 1;
    double y_dir = (quadrant < 2) ? -1 : 1;
    for (size_t level = 0; level < 4; ++level)
    {
      double y_offset = y_dir * (level * heightR_);

      for (size_t rect_in_level = 0; rect_in_level < (4 - level); ++rect_in_level)
      {
        if (index >= 40)
        {
          throw std::out_of_range("Too many rectangles for the array.");
        }
        double x_offset = x_dir * (rect_in_level - (3 - level) / 2.0) * widthR_;
        point_t rect_a = {center.x + x_offset - widthR_ / 2, center.y + y_offset - heightR_ / 2};
        point_t rect_c = {rect_a.x + widthR_, rect_a.y + heightR_};
        rectangles[index] = Rectangle(rect_a, rect_c);
        sumx_ += rectangles[index].getFrameRect().pos.x;
        sumy_ += rectangles[index].getFrameRect().pos.y;
        index++;
      }
    }
  }
}
