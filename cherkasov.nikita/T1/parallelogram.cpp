#include "parallelogram.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

namespace cherkasov
{
  Parallelogram::Parallelogram(double x1, double y1, double x2, double y2, double x3, double y3)
  : vertex1{x1, y1},
    vertex2{x2, y2},
    vertex3{x3, y3},
    vertex4{(x1 + x3) - x2, (y1 + y3) - y2}
    {
      if ((x1 == x3 && y2 == y3) || (x2 == x3 && y1 == y3))
      {
        throw std::invalid_argument("no correct coordinat the parallelogram");
      }
      if (!(y1 == y2 || y1 == y3 || y2 == y3))
      {
        throw std::invalid_argument("sides of the parallelogram must parallel the x");
      }
    }
  double Parallelogram::getArea() const
  {
    double vector1x = vertex2.x - vertex1.x;
    double vector1y = vertex2.y - vertex1.y;
    double vector2x = vertex3.x - vertex1.x;
    double vector2y = vertex3.y - vertex1.y;
    return std::abs(vector1x * vector2y - vector1y * vector2x);
  }
  rectangle_t Parallelogram::getFrameRect() const
  {
    double minX = std::min({vertex1.x, vertex2.x, vertex3.x, vertex4.x});
    double maxX = std::max({vertex1.x, vertex2.x, vertex3.x, vertex4.x});
    double minY = std::min({vertex1.y, vertex2.y, vertex3.y, vertex4.y});
    double maxY = std::max({vertex1.y, vertex2.y, vertex3.y, vertex4.y});
    point_t center;
    center.x = (vertex1.x + vertex2.x + vertex3.x + vertex4.x) / 4;
    center.y = (vertex1.y + vertex2.y + vertex3.y + vertex4.y) / 4;
    rectangle_t rect{};
    rect.width = maxX - minX;
    rect.height = maxY - minY;
    rect.pos = center;
    return rect;
  }
  void Parallelogram::move(point_t c)
  {
    point_t Pos = getFrameRect().pos;
    double dx = c.x - Pos.x;
    double dy = c.y - Pos.y;
    move(dx, dy);
  }
  void Parallelogram::move(double dx, double dy)
  {
    vertex1.x += dx;
    vertex1.y += dy;
    vertex2.x += dx;
    vertex2.y += dy;
    vertex3.x += dx;
    vertex3.y += dy;
    vertex4.x += dx;
    vertex4.y += dy;
  }
  void Parallelogram::scale(double k)
  {
    point_t center = getFrameRect().pos;
    vertex1.x = center.x + (vertex1.x - center.x) * k;
    vertex1.y = center.y + (vertex1.y - center.y) * k;
    vertex2.x = center.x + (vertex2.x - center.x) * k;
    vertex2.y = center.y + (vertex2.y - center.y) * k;
    vertex3.x = center.x + (vertex3.x - center.x) * k;
    vertex3.y = center.y + (vertex3.y - center.y) * k;
    vertex4 = {vertex1.x + vertex3.x - vertex2.x, vertex1.y + vertex3.y - vertex2.y};
  }
}
