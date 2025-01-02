#include "polygon.hpp"
#include <cstddef>
#include <stdexcept>
#include <cmath>
#include "base-types.hpp"
#include <iostream>
zakirov::Polygon::Polygon(size_t size, point_t * points) :
  size_(size),
  points_(points)
{
  if (size <= 2 || size % 2 != 0)
  {
    throw std::invalid_argument("Incorrect data");
  }

  for (size_t i = 0; i < (size - 1); ++i)
  {
    double x = points[i].x;
    double y = points[i].y;
    for (size_t j = (i + 1); j < size; ++j)
    {
      if ((x == points[j].x) && (y == points[j].y))
      {
        throw std::invalid_argument("Incorrect data");
      }
    }
  }
}

double zakirov::Polygon::getArea() const
{
  point_t central_p = {0.0, 0.0};
  double area = 0.0;
  for (size_t i = 0; i < size_; ++i)
  {
    central_p.x += points_[i].x;
    central_p.y += points_[i].y;
  }

  central_p.x /= size_;
  central_p.y /= size_;
  for (size_t i = 0; i < size_; ++i)
  {
    double side_a = get_distance(central_p, points_[i]);
    double side_b = get_distance(central_p, points_[i + 1]);
    double side_c = get_distance(points_[i], points_[i + 1]);
    double half_p = (side_a + side_b + side_c) / 2.0;
    area += std::sqrt(half_p * (half_p - side_a) * (half_p - side_b) * (half_p - side_c));
  }

  return area;
}

zakirov::rectangle_t zakirov::Polygon::getFrameRect() const
{
  rectangle_t сircumscribed;

  double min_x = points_[0].x, min_y = points_[0].y;
  double max_x = points_[0].x, max_y = points_[0].y;

  for (size_t i = 1; i < size_; ++i)
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
  for (size_t i = 0; i < size_; ++i)
  {
    points_[i].x += bias.x;
    points_[i].y += bias.y;
  }
}

void zakirov::Polygon::move(double bias_x, double bias_y)
{
  for (size_t i = 0; i < size_; ++i)
  {
    points_[i].x += bias_x;
    points_[i].y += bias_y;
  }
}

void zakirov::Polygon::scale(double k)
{
  rectangle_t object_frame = getFrameRect();
  for (size_t i = 0; i < size_; ++i)
  {
    points_[i].x = object_frame.pos.x - (object_frame.pos.x - points_[i].x) * k;
    points_[i].y = object_frame.pos.y - (object_frame.pos.y - points_[i].y) * k;
  }
}
