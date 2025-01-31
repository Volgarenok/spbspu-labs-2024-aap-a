#include "diamond.hpp"
#include <cmath>
#include <stdexcept>

smirnov::Diamond::Diamond(point_t p1, point_t p2, point_t p3):
  vertex1{p1},
  vertex2{p2},
  vertex3{p3}
{
  if ((p1.x == p2.x && p1.y == p2.y) && (p1.x == p3.x && p1.y == p3.y))
  {
    throw std::invalid_argument("All three vertices cannot coincide");
  }
  if ((p1.x == p2.x && p1.y == p2.y) || (p1.x == p3.x && p1.y == p3.y)
      || (p2.x == p3.x && p2.y == p3.y))
  {
    throw std::invalid_argument("Two vertices cannot coincide");
  }
}

double smirnov::Diamond::getArea() const
{
  double d1 = std::abs(vertex2.x - vertex1.x);
  double d2 = std::abs(vertex3.y - vertex1.y);
  return 0.5 * d1 * d2;
}

smirnov::rectangle_t smirnov::Diamond::getFrameRect() const
{
  point_t center;
  center.x = (vertex1.x + vertex2.x + vertex3.x) / 3;
  center.y = (vertex1.x + vertex2.x + vertex3.x) / 3;
  double width = std::abs(vertex2.x - vertex1.x);
  double height = std::abs(vertex3.y - vertex1.y);
  return {center, width, height};
}

void smirnov::Diamond::move(point_t newPos)
{
  point_t currentPos = getFrameRect().pos;
  double dx = newPos.x - currentPos.x;
  double dy = newPos.y - currentPos.y;
  move(dx, dy);
}

void smirnov::Diamond::move(double dx, double dy)
{
  vertex1.x += dx;
  vertex1.y += dy;
  vertex2.x += dx;
  vertex2.y += dy;
  vertex3.x += dx;
  vertex3.y += dy;
}

void smirnov::Diamond::scale(double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("Zoom coefficient must be positive");
  }
  point_t center = getFrameRect().pos;
  vertex1.x = (vertex1.x - center.x) * k + center.x;
  vertex1.y = (vertex1.y - center.y) * k + center.y;
  vertex2.x = (vertex2.x - center.x) * k + center.x;
  vertex2.y = (vertex2.y - center.y) * k + center.y;
  vertex3.x = (vertex3.x - center.x) * k + center.x;
  vertex3.y = (vertex3.y - center.y) * k + center.y;
}
