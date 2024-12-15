#include "circle.hpp"
#include <stdexcept>

duhanina::Circle::Circle(point_t pos, double radius)
  : pos_(pos), radius_(radius)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Incorrect radius");
  }
}

double duhanina::Circle::getArea() const
{
  return 3.14 * radius_ * radius_;
}

duhanina::rectangle_t duhanina::Circle::getFrameRect() const
{
  return { pos_, 2 * radius_, 2 * radius_ };
}

void duhanina::Circle::move(point_t newPos)
{
  pos_ = newPos;
}

void duhanina::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void duhanina::Circle::scale(double k)
{
  radius_ *= k;
}
