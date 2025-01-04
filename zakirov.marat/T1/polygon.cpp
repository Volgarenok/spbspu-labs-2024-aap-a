#include "polygon.hpp"
#include <cstddef>
#include <stdexcept>
#include "base-types.hpp"

zakirov::Polygon::Polygon(std::size_t size, point_t * points):
  size_(size),
  points_(points)
{
  if (size <= 2 || size % 2 != 0)
  {
    throw std::invalid_argument("Incorrect data");
  }

  for (std::size_t i = 0; i < (size - 1); ++i)
  {
    double x = points[i].x;
    double y = points[i].y;
    for (std::size_t j = (i + 1); j < size; ++j)
    {
      if ((x == points[j].x) && (y == points[j].y))
      {
        throw std::invalid_argument("Incorrect data");
      }
    }
  }
}

zakirov::Polygon::~Polygon()
{
  free(points_);
}

double zakirov::Polygon::getArea() const
{
  double result = 0;
  for (std::size_t i = 0; i < size_ - 1; ++i)
  {
    result += points_[i].x * points_[i + 1].y - points_[i].y * points_[i + 1].x;
  }
  result += points_[size_ - 1].x * points_[0].y - points_[size_ - 1].y * points_[0].x;
  result *= 0.5;
  return std::abs(result);
}

zakirov::rectangle_t zakirov::Polygon::getFrameRect() const
{
  rectangle_t сircumscribed;

  double min_x = points_[0].x, min_y = points_[0].y;
  double max_x = points_[0].x, max_y = points_[0].y;

  for (std::size_t i = 1; i < size_; ++i)
  {
    min_x = points_[i].x < min_x ? points_[i].x : min_x;
    min_y = points_[i].y < min_y ? points_[i].y : min_y;
    max_x = points_[i].x > max_x ? points_[i].x : max_x;
    max_y = points_[i].y > max_y ? points_[i].y : max_y;
  }

  сircumscribed.width = max_x - min_x;
  сircumscribed.height = max_y - min_y;
  сircumscribed.pos.x = min_x + (сircumscribed.width) / 2;
  сircumscribed.pos.y = min_y + (сircumscribed.height) / 2;

  return сircumscribed;
}

void zakirov::Polygon::move(point_t target)
{
  rectangle_t object_frame = getFrameRect();
  point_t bias = {target.x - object_frame.pos.x, target.y - object_frame.pos.y};
  for (std::size_t i = 0; i < size_; ++i)
  {
    points_[i].x += bias.x;
    points_[i].y += bias.y;
  }
}

void zakirov::Polygon::move(double bias_x, double bias_y)
{
  for (std::size_t i = 0; i < size_; ++i)
  {
    points_[i].x += bias_x;
    points_[i].y += bias_y;
  }
}

void zakirov::Polygon::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect coefficient");
  }

  rectangle_t object_frame = getFrameRect();
  for (std::size_t i = 0; i < size_; ++i)
  {
    points_[i].x = object_frame.pos.x - (object_frame.pos.x - points_[i].x) * k;
    points_[i].y = object_frame.pos.y - (object_frame.pos.y - points_[i].y) * k;
  }
}
