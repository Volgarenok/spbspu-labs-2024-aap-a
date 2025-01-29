#include "polygon.hpp"
#include <cmath>
#include <stdexcept>
#include "output.hpp"
#include "triangle.hpp"
#include "point.hpp"
namespace details
{
  bool it_polygon(const karnauhova::point_t* points, size_t count);
}

karnauhova::Polygon::Polygon(const point_t* points, size_t count_point):
  triangles_(nullptr),
  count_(0)
{
  try
  {
    triangles_ = new Triangle*[count_point - 2];
    if (count_point < 3 || !details::it_polygon(points, count_point))
    {
      delete[] triangles_;
      throw std::logic_error("It's not a polygon");
    }
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
    delete[] points;
  }
  catch (const std::exception& e)
  {
    delete[] points;
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
  rectangle_t rect;
  double min_x = triangles_[0]->getFrameRect().pos.x - triangles_[0]->getFrameRect().width / 2;
  double max_x = triangles_[0]->getFrameRect().pos.x + triangles_[0]->getFrameRect().width / 2;
  double min_y = triangles_[0]->getFrameRect().pos.y - triangles_[0]->getFrameRect().height / 2;
  double max_y = triangles_[0]->getFrameRect().pos.y + triangles_[0]->getFrameRect().height / 2;
  for (size_t i = 1; i < count_; i++)
  {
    rectangle_t rectangl = triangles_[i]->getFrameRect();
    min_x = std::fmin(min_x, rectangl.pos.x - (rectangl.width / 2));
    min_y = std::fmin(min_y, rectangl.pos.y - (rectangl.height / 2));
    max_x = std::fmax(max_x, rectangl.pos.x + (rectangl.width / 2));
    max_y = std::fmax(max_y, rectangl.pos.y + (rectangl.height / 2));
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
  for (size_t i = 0; i < count_; ++i)
  {
    delete triangles_[i];
  }
  delete[] triangles_;
}

karnauhova::Shape* karnauhova::Polygon::clone() const
{
  return new Polygon(*this);
}

bool details::it_polygon(const karnauhova::point_t* points, size_t count)
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
