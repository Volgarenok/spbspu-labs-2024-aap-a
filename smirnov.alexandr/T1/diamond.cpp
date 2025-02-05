#include "diamond.hpp"
#include <cmath>
#include <stdexcept>
constexpr double angle = 90.0;
smirnov::Diamond::Diamond(point_t p1, point_t p2, point_t p3):
  vertex1(p1),
  vertex2(p2),
  vertex3(p3),
  /*center(computeCenter(p1, p2, p3)),*/
  parallelogram(vertex1, vertex2, vertex3)
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
  /*constexpr double angle_rad = angle * M_PI / 180.0;
  vertex1 = rotatePoint(p1, center, angle_rad);
  vertex2 = rotatePoint(p2, center, angle_rad);
  vertex3 = rotatePoint(p3, center, angle_rad);*/
  parallelogram = Parallelogram(vertex1, vertex2, vertex3);
}

/*smirnov::point_t smirnov::Diamond::computeCenter(const point_t & p1,
    const point_t & p2, const point_t & p3) const {
  point_t center;
  center.x = (p1.x + p2.x + p3.x) / 3;
  center.y = (p1.y + p2.y + p3.y) / 3;
  return center;
}

smirnov::point_t smirnov::Diamond::rotatePoint(const point_t & point,
    const point_t & center, double angle_rad) const {
  double x = point.x - center.x;
  double y = point.y - center.y;
  double x_rotated = x * std::cos(angle_rad) - y * std::sin(angle_rad);
  double y_rotated = x * std::sin(angle_rad) + y * std::cos(angle_rad);
  return {x_rotated + center.x, y_rotated + center.y};
}*/

double smirnov::Diamond::getArea() const
{
  return parallelogram.getArea();
}

smirnov::rectangle_t smirnov::Diamond::getFrameRect() const
{
  return parallelogram.getFrameRect();
}

void smirnov::Diamond::move(point_t newPos)
{
  return parallelogram.move(newPos);
}

void smirnov::Diamond::move(double dx, double dy)
{
  parallelogram.move(dx, dy);
}

void smirnov::Diamond::scale(double k)
{
  parallelogram.scale(k);
}
