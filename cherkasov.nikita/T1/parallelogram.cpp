#include "parallelogram.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

namespace cherkasov
{
  Parallelogram::Parallelogram(double x1, double y1, double x2, double y2, double x3, double y3)
  {
    vertex1 = {x1, y1};
    vertex2 = {x2, y2};
    vertex3 = {x3, y3};
    vertex4 = {x3 + (x2 - x1), y3 + (y2 - y1)};
    center = {(vertex1.x + vertex3.x) / 2, (vertex1.y + vertex3.y) / 2};
  }
  double Parallelogram::getArea() const
  {
    double vector1x = vertex2.x - vertex1.x;
    double vector1y = vertex2.y - vertex1.y;
    double vector2x = vertex3.x - vertex1.x;
    double vector2y = vertex3.y - vertex1.y;
    double area = std::abs(vector1x * vector2y - vector1y * vector2x);
    return area;
  }
  rectangle_t Parallelogram::getFrameRect() const
  {
    double minX = std::min({vertex1.x, vertex2.x, vertex3.x, vertex4.x});
    double maxX = std::max({vertex1.x, vertex2.x, vertex3.x, vertex4.x});
    double minY = std::min({vertex1.y, vertex2.y, vertex3.y, vertex4.y});
    double maxY = std::max({vertex1.y, vertex2.y, vertex3.y, vertex4.y});
    rectangle_t rect;
    rect.width = maxX - minX;
    rect.height = maxY - minY;
    rect.pos = {(minX + maxX) / 2.0, (minY + maxY) / 2};
    return rect;
  }
  void Parallelogram::move(point_t c)
  {
    double dx = c.x - center.x;
    double dy = c.y - center.y;
    vertex1.x += dx;
    vertex1.y += dy;
    vertex2.x += dx;
    vertex2.y += dy;
    vertex3.x += dx;
    vertex3.y += dy;
    vertex4.x += dx;
    vertex4.y += dy;
    center = c;
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
    center.x += dx;
    center.y += dy;
  }
  void Parallelogram::scale(double k)
  {
    vertex1.x = center.x + (vertex1.x - center.x) * k;
    vertex1.y = center.y + (vertex1.y - center.y) * k;
    vertex2.x = center.x + (vertex2.x - center.x) * k;
    vertex2.y = center.y + (vertex2.y - center.y) * k;
    vertex3.x = center.x + (vertex3.x - center.x) * k;
    vertex3.y = center.y + (vertex3.y - center.y) * k;
    vertex4.x = center.x + (vertex4.x - center.x) * k;
    vertex4.y = center.y + (vertex4.y - center.y) * k;
  }
}
