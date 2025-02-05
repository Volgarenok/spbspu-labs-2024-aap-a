#include "ellipse.hpp"
#include <stdexcept>
#include "movingPoint.hpp"

duhanina::Ellipse::Ellipse(const point_t& center, double vertRadius, double horizRadius):
  center_(center),
  vertRadius_(vertRadius),
  horizRadius_(horizRadius)
{
  if (vertRadius <= 0 || horizRadius <= 0)
  {
    throw std::invalid_argument("Error in parameters");
  }
}

double duhanina::Ellipse::getArea() const
{
  constexpr double pi = 3.1415;
  return pi * horizRadius_ * vertRadius_;
}

duhanina::rectangle_t duhanina::Ellipse::getFrameRect() const
{
  return { center_, 2 * horizRadius_, 2 * vertRadius_ };
}

void duhanina::Ellipse::move(const point_t& newPos)
{
  center_ = newPos;
}

void duhanina::Ellipse::move(double dx, double dy)
{
  movePoint(center_, dx, dy);
}

void duhanina::Ellipse::scaleUnsafe(double k) noexcept
{
  horizRadius_ *= k;
  vertRadius_ *= k;
}
