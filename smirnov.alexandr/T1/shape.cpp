#include "shape.hpp"
#include <stdexcept>

void smirnov::Shape::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale");
  }
  unsafeScale(k);
}

void smirnov::Shape::applyMove(point_t & point, double dx, double dy)
{
  point.x += dx;
  point.y += dy;
}

void smirnov::Shape::applyScale(point_t & point, const point_t & center, double k)
{
  point.x = center.x + (point.x - center.x) * k;
  point.y = center.y + (point.y - center.y) * k;
}
