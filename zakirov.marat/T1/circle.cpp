#include "circle.hpp"
#include <cmath>
#include <stdexcept>
#include "shape.hpp"

zakirov::Circle::Circle(point_t center, double radius):
  center_(center),
  radius_(radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Incorrect data");
  }
}

double zakirov::Circle::getArea() const
{
  constexpr double pi = 3.14;
  return pi * std::pow(radius_, 2);
}

zakirov::rectangle_t zakirov::Circle::getFrameRect() const
{
  rectangle_t сircumscribed{radius_ * 2, radius_* 2, center_};
  return сircumscribed;
}

void zakirov::Circle::move(point_t target)
{
  center_ = target;
}

void zakirov::Circle::move(double bias_x, double bias_y)
{
  center_.x += bias_x;
  center_.y += bias_y;
}

void zakirov::Circle::scale(double k)
{
  radius_ *= k;
}
