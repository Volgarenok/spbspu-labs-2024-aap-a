#include "ellipse.hpp"

duhanina::Ellipse::Ellipse(point_t center, double horizRadius, double vertRadius)
  : center_(center), horizRadius_(horizRadius), vertRadius_(vertRadius) {}

double duhanina::Ellipse::getArea() const
{
  return 3.14 * horizRadius_ * vertRadius_;
}

duhanina::rectangle_t duhanina::Ellipse::getFrameRect() const
{
  return { center_, 2 * horizRadius_, 2 * vertRadius_ };
}

void duhanina::Ellipse::move(point_t newPos)
{
  center_ = newPos;
}

void duhanina::Ellipse::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void duhanina::Ellipse::scale(double k)
{
  horizRadius_ *= k;
  vertRadius_ *= k;
}
