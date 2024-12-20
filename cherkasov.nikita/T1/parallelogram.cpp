#include "parallelogram.h"
#include <stdexcept>
#include <cmath>

namespace cherkasov
{
  Parallelogram::Parallelogram(point_t point1, point_t point2, point_t point3)
  : point1(point1), point2(point2), point3(point3)
  {
    if ((point1.x == point2.x && point1.y == point2.y) ||
        (point1.x == point3.x && point1.y == point3.y) ||
        (point2.x == point3.x && point2.y == point3.y))
    {
      throw std::logic_error("Parallelogram vertices must be distinct");
    }
    if (point1.y != point2.y)
    {
      throw std::logic_error("One side must be parallel to the X-axis");
    }
    calculateCenter();
  }
  void Parallelogram::calculateCenter()
  {
    length = std::abs(point2.x - point1.x);
    height = std::abs(point3.y - point1.y);
    center.x = (point1.x + point2.x + point3.x + (point3.x - point1.x)) / 4;
    center.y = (point1.y + point2.y + point3.y + (point3.y - point2.y)) / 4;
  }
  double Parallelogram::getArea() const
  {
    return length * height;
  }
  rectangle_t Parallelogram::getFrameRect() const
  {
    return {length, height, center};
  }
  void Parallelogram::move(point_t c)
  {
    double dx = c.x - center.x;
    double dy = c.y - center.y;
    point1.x += dx;
    point1.y += dy;
    point2.x += dx;
    point2.y += dy;
    point3.x += dx;
    point3.y += dy;
    center = c;
  }
  void Parallelogram::move(double dx, double dy)
  {
    point1.x += dx;
    point1.y += dy;
    point2.x += dx;
    point2.y += dy;
    point3.x += dx;
    point3.y += dy;
    center.x += dx;
    center.y += dy;
  }
  void Parallelogram::scale(double k)
  {
    if (k <= 0)
    {
      throw std::logic_error("Scale factor must be positive");
    }
    point1.x = center.x + (point1.x - center.x) * k;
    point1.y = center.y + (point1.y - center.y) * k;
    point2.x = center.x + (point2.x - center.x) * k;
    point2.y = center.y + (point2.y - center.y) * k;
    point3.x = center.x + (point3.x - center.x) * k;
    point3.y = center.y + (point3.y - center.y) * k;
    calculateCenter();
  }
}
