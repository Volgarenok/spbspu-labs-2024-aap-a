#include "circle.hpp"
#include <cmath>
#include <stdexcept>
#include "unified_shapes.hpp"
#include "ring.hpp"

zakirov::Circle::Circle(point_t center, double radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Incorrect data");
  }

  double step = (radius - first_in_radius_) / rings_size_;
  for (size_t i = 0; i < rings_size_; ++i)
  {
    Ring ring(center, (i * step) + first_in_radius_, i * (step + 1) + first_in_radius_);
    rings_[i] = & ring;
  }
}

double zakirov::Circle::getArea() const
{
  double total_area = 0;
  for (size_t i; i < rings_size_; ++i)
  {
    total_area += rings_[i]->getArea();
  }

  return total_area;
}

zakirov::rectangle_t zakirov::Circle::getFrameRect() const
{
  return rings_[rings_size_ - 1]->getFrameRect();
}

void zakirov::Circle::move(point_t target)
{
  for (size_t i; i < rings_size_; ++i)
  {
    rings_[i]->move(target);
  }
}

void zakirov::Circle::move(double bias_x, double bias_y)
{
  for (size_t i; i < rings_size_; ++i)
  {
    rings_[i]->move(bias_x, bias_y);
  }
}

void zakirov::Circle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect coefficient");
  }

  for (size_t i; i < rings_size_; ++i)
  {
    rings_[i]->scale(k);
  }
}
