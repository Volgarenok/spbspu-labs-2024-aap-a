#include "rectangle.hpp"
#include <stdexcept>

smirnov::Rectangle::Rectangle(double x1, double y1, double x2, double y2):
  lowerLeft_{x1, y1},
  upperRight_{x2, y2}
{
  if (x1 >= x2 || y1 >= y2)
  {
    throw std::invalid_argument("Incorrect coordinates");
  }
}

double smirnov::Rectangle::getArea() const
{
  return (upperRight_.x - lowerLeft_.x) * (upperRight_.y - lowerLeft_.y);
}

smirnov::rectangle_t smirnov::Rectangle::getFrameRect() const
{
  point_t center = {(lowerLeft_.x + upperRight_.x) / 2, (lowerLeft_.y + upperRight_.y) / 2};
  return {center, upperRight_.x - lowerLeft_.x, upperRight_.y - lowerLeft_.y};
}

void smirnov::Rectangle::move(point_t newPos)
{
  point_t currentPos = getFrameRect().pos;
  double dx = newPos.x - currentPos.x;
  double dy = newPos.y - currentPos.y;
  move(dx, dy);
}

void smirnov::Rectangle::move(double dx, double dy)
{
  applyMove(lowerLeft_, dx, dy);
  applyMove(upperRight_, dx, dy);
}

void smirnov::Rectangle::unsafeScale(double k) noexcept
{
  point_t center = getFrameRect().pos;
  applyScale(lowerLeft_, center, k);
  applyScale(upperRight_, center, k);
}
