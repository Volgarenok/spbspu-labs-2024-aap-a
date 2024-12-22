#include "diamond.h"
#include <stdexcept>
#include <cmath>
#include <algorithm>

namespace cherkasov
{
  Diamond::Diamond(double x1, double y1, double x2, double y2, double x3, double y3)
  {
    if (x1 != x3 || y2 != y3)
    {
      throw std::invalid_argument("Diagonals of the diamond must be parallel to the coordinate");
    }
    vertex1_.x = x1;
    vertex1_.y = y1;
    vertex2_.x = x2;
    vertex2_.y = y2;
    vertex3_.x = x3;
    vertex3_.y = y3;
    center_.x = (x1 + x3) / 2;
    center_.y = (y1 + y3) / 2;
    vertex4_.x = x2 + (x1 - x3);
    vertex4_.y = y2 + (y3 - y1);
  }
  double Diamond::getArea() const
  {
    double diag1 = std::abs(vertex1_.y - vertex3_.y);
    double diag2 = std::abs(vertex2_.x - vertex4_.x);
    return (diag1 * diag2) / 2;
  }
  rectangle_t Diamond::getFrameRect() const
  {
    double minX = std::min({vertex1_.x, vertex2_.x, vertex3_.x, vertex4_.x});
    double maxX = std::max({vertex1_.x, vertex2_.x, vertex3_.x, vertex4_.x});
    double minY = std::min({vertex1_.y, vertex2_.y, vertex3_.y, vertex4_.y});
    double maxY = std::max({vertex1_.y, vertex2_.y, vertex3_.y, vertex4_.y});
    rectangle_t rect;
    rect.width = maxX - minX;
    rect.height = maxY - minY;
    rect.pos.x = center_.x;
    rect.pos.y = center_.y;
    return rect;
  }
  void Diamond::move(point_t c)
  {
    double moveX = c.x - center_.x;
    double moveY = c.y - center_.y;
    vertex1_.x += moveX;
    vertex1_.y += moveY;
    vertex2_.x += moveX;
    vertex2_.y += moveY;
    vertex3_.x += moveX;
    vertex3_.y += moveY;
    vertex4_.x += moveX;
    vertex4_.y += moveY;
    center_ = c;
  }
  void Diamond::move(double dx, double dy)
  {
    vertex1_.x += dx;
    vertex1_.y += dy;
    vertex2_.x += dx;
    vertex2_.y += dy;
    vertex3_.x += dx;
    vertex3_.y += dy;
    vertex4_.x += dx;
    vertex4_.y += dy;
    center_.x += dx;
    center_.y += dy;
  }
  void Diamond::scale(double k)
  {
    vertex1_.x = center_.x + (vertex1_.x - center_.x) * k;
    vertex1_.y = center_.y + (vertex1_.y - center_.y) * k;
    vertex2_.x = center_.x + (vertex2_.x - center_.x) * k;
    vertex2_.y = center_.y + (vertex2_.y - center_.y) * k;
    vertex3_.x = center_.x + (vertex3_.x - center_.x) * k;
    vertex3_.y = center_.y + (vertex3_.y - center_.y) * k;
    vertex4_.x = center_.x + (vertex4_.x - center_.x) * k;
    vertex4_.y = center_.y + (vertex4_.y - center_.y) * k;
  }
}
