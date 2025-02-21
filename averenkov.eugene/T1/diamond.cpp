#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"

namespace
{
  bool checkPoints(const averenkov::point_t& a, const averenkov::point_t& b, const averenkov::point_t& c)
  {
    bool check = (a.x == b.x && a.y == c.y);
    check = check || (a.x == c.x && a.y == b.y);
    check = check || (b.x == a.x && b.y == c.y);
    check = check || (b.x == c.x && b.y == a.y);
    check = check || (c.x == a.x && c.y == b.y);
    check = check || (c.x == b.x && c.y == a.y);
    return check;
  }
  void destroy(averenkov::Rectangle** list)
  {
    for (size_t i = 0; i < 40; i++)
    {
      delete list[i];
    }
    delete[] list;
  }

  averenkov::Rectangle** buildRectangles(const averenkov::point_t& a, const averenkov::point_t& b, const averenkov::point_t& c)
  {
    averenkov::Rectangle** rectangles = new averenkov::Rectangle*[40];
    double width = 0, height = 0;
    averenkov::point_t center = { 0.0, 0.0 };
    width = std::abs(c.x - a.x) + std::abs(b.x - a.x) + std::abs(c.x - b.x);
    height = std::abs(c.y - a.y) + std::abs(b.y - a.y) + std::abs(c.y - b.y);
    if ((a.x == b.x && a.y == c.y) || (a.x == c.x && a.y == b.y))
    {
      center = a;
    }
    else if ((b.x == a.x && b.y == c.y) || (b.x == c.x && b.y == a.y))
    {
      center = b;
    }
    else if ((c.x == a.x && c.y == b.y) || (c.x == b.x && c.y == a.y))
    {
      center = c;
    }
    if (width == 0 || height == 0)
    {
      delete[] rectangles;
      throw std::invalid_argument("Incorrect input");
    }
    double widthR_ = width / 8;
    double heightR_ = height / 8;
    size_t index = 0;
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
            destroy(rectangles);
            throw std::out_of_range("Too many rectangles for the array.");
          }
          double x_offset = x_dir * (rect_in_level - (3 - level) / 2.0) * widthR_;
          averenkov::point_t rect_a = {center.x + x_offset - widthR_ / 2, center.y + y_offset - heightR_ / 2};
          averenkov::point_t rect_c = {rect_a.x + widthR_, rect_a.y + heightR_};
          try
          {
            rectangles[index] = new averenkov::Rectangle(rect_a, rect_c);
          }
          catch (...)
          {
            destroy(rectangles);
            throw;
          }
          index++;
        }
      }
    }
    return rectangles;
  }
}

averenkov::Diamond::Diamond(const point_t& a, const point_t& b, const point_t& c):
  rectangles_(buildRectangles(a, b, c))
{
  if (!checkPoints(a, b, c))
  {
    destroy(rectangles_);
    throw std::invalid_argument("Error in parameters");
  }
}

averenkov::Diamond::~Diamond()
{
  destroy(rectangles_);
}

double averenkov::Diamond::getArea() const
{
  return rectangles_[1]->getArea() * 8 * 4;
}

averenkov::rectangle_t averenkov::Diamond::getFrameRect() const
{
  double sumx = 0.0;
  double sumy = 0.0;
  for (size_t i = 0; i < 40; i++)
  {
    sumx += rectangles_[i]->getFrameRect().pos.x;
    sumy += rectangles_[i]->getFrameRect().pos.y;
  }
  point_t center = { ( sumx / 40 ), ( sumy / 40 ) };
  double width = rectangles_[1]->getFrameRect().width * 8;
  double height = rectangles_[1]->getFrameRect().height * 8;
  return { width, height, center };
}

void averenkov::Diamond::scaleNonChecked(double factor)
{
  point_t center = getFrameRect().pos;
  double scale_width = getFrameRect().width / 2 * factor;
  double scale_height = getFrameRect().height / 2 * factor;
  point_t a = {center.x + scale_width, center.y};
  point_t b = {center.x, center.y + scale_height};
  Rectangle** rectangles = (buildRectangles(center, a, b));
  destroy(rectangles_);
  rectangles_ = rectangles;
}

void averenkov::Diamond::move(const point_t& new_pos)
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
    rectangles_[i]->move(dx, dy);
  }
}
