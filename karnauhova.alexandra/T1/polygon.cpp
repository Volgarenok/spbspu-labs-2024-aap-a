#include "polygon.hpp"
#include <cmath>
#include <stdexcept>
#include "check.hpp"
karnauhova::Polygon::Polygon(point_t* points, size_t count):
  points_(nullptr),
  count_(count)
{
  try
  {
    points_ = new point_t[count_];
    if (count_ < 3 || !karnauhova::it_polygon(points, count_))
    {
      delete[] points_;
      throw std::logic_error("It's not a polygon");
    }
    points_ = points;
  }
  catch (const std::exception& e)
  {
    throw;
  }
}

double karnauhova::Polygon::getArea() const
{
  double area = 0;
  for (size_t i = 0; i < count_; ++i)
  {
    int j = (i + 1) % count_;
    area += points_[i].x * points_[j].y;
    area -= points_[j].x * points_[i].y;
  }
  return std::abs(area) / 2;
}

karnauhova::rectangle_t karnauhova::Polygon::getFrameRect() const
{
  rectangle_t rect;
  double max_x = points_[0].x;
  double min_x = points_[0].x;
  double max_y = points_[0].y;
  double min_y = points_[0].y;
  for (size_t i = 1; i < count_; i++)
  {
    min_x = std::fmin(min_x, points_[i].x);
    min_y = std::fmin(min_y, points_[i].y);
    max_x = std::fmax(max_x, points_[i].x);
    max_y = std::fmax(max_y, points_[i].y);
  }
  rect.width = max_x - min_x;
  rect.height = max_y - min_y;
  rect.pos.x = min_x + (rect.width / 2);
  rect.pos.y = min_y + (rect.height / 2);
  return rect;
}

void karnauhova::Polygon::move(double x, double y)
{
  for (size_t i = 0; i < count_; ++i)
  {
    points_[i].x += x;
    points_[i].y += y;
  }
}

void karnauhova::Polygon::move(point_t t)
{
  point_t centr = getFrameRect().pos;
  double dif_x = t.x - centr.x;
  double dif_y = t.y - centr.y;
  for (size_t i = 0; i < count_; i++)
  {
    points_[i].x += dif_x;
    points_[i].y += dif_y;
  }
}

void karnauhova::Polygon::scale(double k)
{
  point_t t = getFrameRect().pos;
  for (size_t i = 0; i < count_; i++)
  {
     points_[i].x = t.x + (points_[i].x - t.x) * k;
     points_[i].y = t.y + (points_[i].y - t.y) * k;
  }
}

karnauhova::Polygon::~Polygon()
{
  delete[] points_;
}
