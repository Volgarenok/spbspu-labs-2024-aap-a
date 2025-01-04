#include "circle.hpp"
#include <stdexcept>

duhanina::Circle::Circle(const point_t& pos, const double& radius):
  pos_(pos),
  radius_(radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Error in parameters");
  }
}

double duhanina::Circle::getArea() const
{
  constexpr double pi = 3.1415;
  return pi * radius_ * radius_;
}

duhanina::rectangle_t duhanina::Circle::getFrameRect() const
{
  return { pos_, 2 * radius_, 2 * radius_ };
}

void duhanina::Circle::move(const point_t& newPos)
{
  pos_ = newPos;
}

void duhanina::Circle::move(double dx, double dy)
{
  point_t newPos = { pos_.x + dx, pos_.y + dy };
  move(newPos);
}

void duhanina::Circle::scale(double k)
{
  radius_ *= k;
}
