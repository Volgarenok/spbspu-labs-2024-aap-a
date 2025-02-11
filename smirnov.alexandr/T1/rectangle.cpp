#include "rectangle.hpp"
#include <stdexcept>

smirnov::Rectangle::Rectangle(double x1, double y1, double x2, double y2):
  lowerLeft{x1, y1},
  upperRight{x2, y2}
{
  if (x1 >= x2 || y1 >= y2)
  {
    throw std::invalid_argument("Incorrect coordinates");
  }
}

double smirnov::Rectangle::getArea() const
{
  return (upperRight.x - lowerLeft.x) * (upperRight.y - lowerLeft.y);
}

smirnov::rectangle_t smirnov::Rectangle::getFrameRect() const
{
  point_t center = {(lowerLeft.x + upperRight.x) / 2, (lowerLeft.y + upperRight.y) / 2};
  return {center, upperRight.x - lowerLeft.x, upperRight.y - lowerLeft.y};
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
  applyMove(lowerLeft, dx, dy);
  applyMove(upperRight, dx, dy);
}

void smirnov::Rectangle::scale(double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("Zoom coefficient must be positive");
  }
  point_t center = getFrameRect().pos;
  applyScale(lowerLeft, center, k);
  applyScale(upperRight, center, k);
}
