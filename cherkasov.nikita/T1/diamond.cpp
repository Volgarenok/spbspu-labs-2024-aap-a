#include "diamond.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

namespace cherkasov
{
  Diamond::Diamond(double x1, double y1, double x2, double y2, double x3, double y3)
  {
    vertex1.x = x1;
    vertex1.y = y1;
    vertex2.x = x2;
    vertex2.y = y2;
    vertex3.x = x3;
    vertex3.y = y3;
    center.x = (x1 + x3) / 2;
    center.y = (y1 + y3) / 2;
    vertex4.x = x2 + (x1 - x3);
    vertex4.y = y2 + (y3 - y1);
  }
  double Diamond::getArea() const
  {
    double diag1 = std::abs(vertex1.y - vertex3.y);
    double diag2 = std::abs(vertex2.x - vertex4.x);
    return (diag1 * diag2) / 2;
  }
  rectangle_t Diamond::getFrameRect() const
  {
    double minX = std::min({ vertex1.x, vertex2.x, vertex3.x, vertex4.x });
    double maxX = std::max({ vertex1.x, vertex2.x, vertex3.x, vertex4.x });
    double minY = std::min({ vertex1.y, vertex2.y, vertex3.y, vertex4.y });
    double maxY = std::max({ vertex1.y, vertex2.y, vertex3.y, vertex4.y });
    cherkasov::rectangle_t rect{};
    rect.width = maxX - minX;
    rect.height = maxY - minY;
    rect.pos.x = center.x;
    rect.pos.y = center.y;
    return rect;
  }
  void Diamond::move(point_t c)
  {
    double moveX = c.x - center.x;
    double moveY = c.y - center.y;
    vertex1.x += moveX;
    vertex1.y += moveY;
    vertex2.x += moveX;
    vertex2.y += moveY;
    vertex3.x += moveX;
    vertex3.y += moveY;
    vertex4.x += moveX;
    vertex4.y += moveY;
    center = c;
  }
  void Diamond::move(double dx, double dy)
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
  void Diamond::scale(double k)
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
