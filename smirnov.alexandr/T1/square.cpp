#include "square.hpp"
#include <stdexcept>

smirnov::Square::Square(double x, double y, double length):
  lowerLeft_{x, y},
  sideLength_(length)
{
  if (length <= 0)
  {
    throw std::invalid_argument("Side length must be positive");
  }
}

double smirnov::Square::getArea() const
{
  return sideLength_ * sideLength_;
}

smirnov::rectangle_t smirnov::Square::getFrameRect() const
{
  point_t center = {lowerLeft_.x + sideLength_ / 2, lowerLeft_.y + sideLength_ / 2};
  return {center, sideLength_, sideLength_};
}

void smirnov::Square::move(point_t newPos)
{
  point_t currentPos = getFrameRect().pos;
  double dx = newPos.x - currentPos.x;
  double dy = newPos.y - currentPos.y;
  move(dx, dy);
}

void smirnov::Square::move(double dx, double dy)
{
  applyMove(lowerLeft_, dx, dy);
}

void smirnov::Square::unsafeScale(double k) noexcept
{
  point_t center = getFrameRect().pos;
  sideLength_ *= k;
  applyScale(lowerLeft_, center, k);
}
