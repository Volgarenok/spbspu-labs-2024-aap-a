#include "circle.hpp"
#include <cmath>
#include <cstddef>
#include <stdexcept>
#include "ring.hpp"

zakirov::Circle::Circle(const point_t & center, double radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Incorrect data");
  }

  double step = (radius - first_in_radius_) / rings_size_;
  for (size_t i = 0; i < rings_size_; ++i)
  {
    Ring * ring = static_cast< Ring * >(malloc(sizeof(Ring)));
    if (!ring)
    {
      throw std::bad_alloc();
    }

    rings_[i] = new (ring) Ring(center, step * (i + 1) + first_in_radius_, step * i + first_in_radius_);
  }
}

zakirov::Circle::~Circle()
{
  for (size_t i = 0; i < rings_size_; ++i)
  {
    rings_[i]->~Ring();
    free(rings_[i]);
  }
}

double zakirov::Circle::getArea() const
{
  double total_area = 0.0;
  for (size_t i = 0; i < rings_size_; ++i)
  {
    total_area += rings_[i]->getArea();
  }
  return total_area;
}

zakirov::rectangle_t zakirov::Circle::getFrameRect() const
{
  return rings_[rings_size_ - 1]->getFrameRect();
}

void zakirov::Circle::move(const point_t & target)
{
  move(target.x - getFrameRect().pos.x, target.y - getFrameRect().pos.y);
}

void zakirov::Circle::move(double bias_x, double bias_y)
{
  for (size_t i = 0; i < rings_size_; ++i)
  {
    rings_[i]->move(bias_x, bias_y);
  }
}

void zakirov::Circle::scale(double k) noexcept
{
  for (size_t i = 0; i < rings_size_; ++i)
  {
    rings_[i]->scale(k);
  }
}

zakirov::Shape * zakirov::Circle::clone() const
{
  point_t center = getFrameRect().pos;
  double radius = getFrameRect().width / 2;
  Circle * circle = nullptr;
  try
  {
    Circle * circle = static_cast< Circle * >(malloc(sizeof(Circle)));
    if (!circle)
    {
      throw std::bad_alloc();
    }

    new (circle) Circle(center, radius);
    return circle;
  }
  catch (const std::exception &)
  {
    free(circle);
    throw;
  }
}
