#include "square.hpp"

namespace abramov
{
  Square::Square(double x, double y, double len):
    pLeftLower.x(x), pLeftLower.y(y), len_(len)
  {}

  double Square::getArea() const
  {
    return len_ * len_;
  }

  rectangle_t getFrameRect() const
  {
    point_t pos;
    pos.x = pLeftLower.x + len_ / 2;
    pos.y = pLeftLower.y + len_ / 2;
    rectangle_t frame_rect;
    frame_rect.height = len_;
    frame_rect.width = len_;
    frame_rect.pos = pos;
    return frame_rect;
  }

  void move(double dx, double dy)
  {
    pLeftLower.x += dx;
    pLeftLower.y += dy;
  }

  void move(point_t p)
  {
    point_t center = getFrameRect().pos;
    double dx = p.x - center.x;
    double dy = p.y - center.y;
    move(dx, dy);
  }

  void scale(double k)
  {
    len_ *= k;
    pLeftLower.x += len_ / 2 * (k - 1);
    pLeftLower.y += len_ / 2 * (k - 1);
  }
}
