#include "circle.hpp"
#include <stdexcept>
#include <cmath>

balashov::Circle::Circle(point_t center, double radius)
{
  center_ =center;
  radius_ = radius;

  if (radius <= 0)
  {
    throw std::invalid_argument("Incorrect data");
  }
}

double balashov::Circle::getArea() const
{
  const double pi = 3.14;
  return pi * pow(radius_, 2);
}

balashov::rectangle_t balashov::Circle::getFrameRect() const
{
  rectangle_t сircumscribed;
  сircumscribed.width_ = radius_;
  сircumscribed.height_ = radius_;
  сircumscribed.pos_ = center_;

  return сircumscribed;
}

void balashov::Circle::move(point_t target)
{
  center_ = target;
}

void balashov::Circle::move(double x, double y)
{
  center_.x_ += x;
  center_.y_ += y;
}

void balashov::Circle::scale(double k)
{
  radius_ *= pow(k, 2) ;
}
