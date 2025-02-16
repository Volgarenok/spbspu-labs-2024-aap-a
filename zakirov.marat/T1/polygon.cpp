#include "polygon.hpp"
#include <cstddef>
#include <stdexcept>
#include "base-types.hpp"

zakirov::Polygon::Polygon(size_t size, point_t * points):
  size_(size),
  points_(points)
{
  if (size <= 2 || size % 2 != 0)
  {
    throw std::invalid_argument("Incorrect data");
  }

  for (size_t i = 0; i < (size - 1); ++i)
  {
    double x = points_[i].x;
    double y = points_[i].y;
    for (size_t j = (i + 1); j < size; ++j)
    {
      if ((x == points_[j].x) && (y == points_[j].y))
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
  for (size_t i = 0; i < size_ - 1; ++i)
  {
    result += points_[i].x * points_[i + 1].y - points_[i].y * points_[i + 1].x;
  }
  result += points_[size_ - 1].x * points_[0].y - points_[size_ - 1].y * points_[0].x;
  result *= 0.5;
  return std::abs(result);
}

zakirov::rectangle_t zakirov::Polygon::getFrameRect() const
{
  double min_x = points_[0].x;
  double min_y = points_[0].y;
  double max_x = points_[0].x;
  double max_y = points_[0].y;
  for (size_t i = 1; i < size_; ++i)
  {
    min_x = std::min(points_[i].x, min_x);
    min_y = std::min(points_[i].y, min_y);
    max_x = std::max(points_[i].x, max_x);
    max_y = std::max(points_[i].y, max_y);
  }

  return {max_x - min_x, max_y - min_y, get_middle({min_x, min_y}, {max_x, max_y})};
}

void zakirov::Polygon::move(const point_t & target)
{
  rectangle_t object_frame = getFrameRect();
  point_t bias = {target.x - object_frame.pos.x, target.y - object_frame.pos.y};
  move(bias.x, bias.y);
}

void zakirov::Polygon::move(double bias_x, double bias_y)
{
  for (size_t i = 0; i < size_; ++i)
  {
    move_point(points_[i], bias_x, bias_y);
  }
}

void zakirov::Polygon::scale(double k) noexcept
{
  rectangle_t object_frame = getFrameRect();
  for (size_t i = 0; i < size_; ++i)
  {
    points_[i].x = object_frame.pos.x - (object_frame.pos.x - points_[i].x) * k;
    points_[i].y = object_frame.pos.y - (object_frame.pos.y - points_[i].y) * k;
  }
}

zakirov::Shape * zakirov::Polygon::clone() const
{
  Polygon * polygon = nullptr;
  try
  {
    Polygon * polygon = static_cast< Polygon * >(malloc(sizeof(Polygon)));
    if (!polygon)
    {
      throw std::bad_alloc();
    }

    new (polygon) Polygon(size_, points_);
    return polygon;
  }
  catch (const std::exception &)
  {
    free(polygon);
    throw;
  }
}
