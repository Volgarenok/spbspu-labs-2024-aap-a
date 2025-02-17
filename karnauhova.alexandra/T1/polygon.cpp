#include "polygon.hpp"
#include <cmath>
#include <stdexcept>
#include "output.hpp"
#include "triangle.hpp"
#include "point.hpp"
namespace
{
  bool is_polygon(const karnauhova::point_t* points, size_t count)
  {
    for (size_t i = 0; i < count; i ++)
    {
      for (size_t j = i + 1; j < count; j++)
      {
        if (karnauhova::isEqual(points[i], points[j]))
        {
          return false;
        }
      }
    }
    return true;
  }
}

void karnauhova::Polygon::clear() noexcept
{
  for (size_t i = 0; i < count_; i++)
  {
    delete triangles_[i];
  }
  delete[] triangles_;
}

karnauhova::Polygon::Polygon(const point_t* points, size_t count_point):
  triangles_(nullptr),
  count_(0)
{
  if (count_point < 3 || !is_polygon(points, count_point))
  {
    throw std::logic_error("It's not a polygon");
  }
  try
  {
    triangles_ = new Shape*[count_point - 2];
    for (size_t i = 0; i < (count_point - 2); i += 2)
    {
      triangles_[count_] = new Triangle(points[i], points[i + 1], points[i + 2]);
      count_++;
    }
    if (count_point % 2 == 0)
    {
      triangles_[count_] = new Triangle(points[0], points[count_point - 1], points[count_point - 2]);
      count_++;
    }
    for (size_t i = 2; i < (count_point - 2); i += 2)
    {
      triangles_[count_] = new Triangle(points[0], points[i], points[i + 2]);
      count_++;
    }
  }
  catch (const std::exception& e)
  {
    clear();
    throw;
  }
}

double karnauhova::Polygon::getArea() const
{
  double area = 0;
  for (size_t i = 0; i < count_; ++i)
  {
    area += triangles_[i]->getArea();
  }
  return area;
}

karnauhova::rectangle_t karnauhova::Polygon::getFrameRect() const
{
  return frameRect(triangles_, count_);
}

void karnauhova::Polygon::move(double x, double y)
{
  for (size_t i = 0; i < count_; ++i)
  {
    triangles_[i]->move(x, y);
  }
}

void karnauhova::Polygon::move(const point_t& t)
{
  point_t centr = getFrameRect().pos;
  double dif_x = t.x - centr.x;
  double dif_y = t.y - centr.y;
  move(dif_x, dif_y);
}

void karnauhova::Polygon::scale(double k)
{
  point_t t = getFrameRect().pos;
  for (size_t i = 0; i < count_; i++)
  {
    scale_point(triangles_[i], t, k);
  }
}

karnauhova::Polygon::~Polygon()
{
  clear();
}

karnauhova::Shape* karnauhova::Polygon::clone() const
{
  return new Polygon(*this);
}
