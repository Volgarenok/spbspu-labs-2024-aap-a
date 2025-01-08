#include "diamond.hpp"
#include <cmath>
#include <stdexcept>

smirnov::Diamond::Diamond(double x1, double y1, double x2, double y2, double x3, double y3):
  vertex1{x1, y1},
  vertex2{x2, y2},
  vertex3{x3, y3}
{
  if ((x1 == x2 && y1 == y2) && (x1 == x3 && y1 == y3))
  {
    throw std::invalid_argument("All three vertices cannot coincide");
  }
  if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3))
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
