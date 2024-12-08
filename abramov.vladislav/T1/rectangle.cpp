#include "rectangle.hpp"
#include <stdexcept>
#include "shape.hpp"
#include "base-types.hpp"

namespace abramov
{
  Rectangle::Rectangle(point_t p1, point_t p2)
  {
    if (p1.x >= p2.x || p1.y >= p2.y)
    {
      throw std::logic_error("Impossible to build a rectangle");
    }
    pLeftLower_ = p1;
    pRightUpper_ = p2;
  }

  double Rectangle::getArea() const
  {
    return (pRightUpper_.x - pLeftLower_.x) * (pRightUpper_.y - pLeftLower_.y);
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    point_t pos;
    pos.x = (pRightUpper_.x + pLeftLower_.x) / 2;
    pos.y = (pRightUpper_.y + pLeftLower_.y) / 2;
    rectangle_t frame_rect;
    frame_rect.width = pRightUpper_.x - pLeftLower_.x;
    frame_rect.height = pRightUpper_.y - pLeftLower_.y;
    frame_rect.pos = pos;
    return frame_rect;
  }

  void Rectangle::move(double dx, double dy)
  {
    pRightUpper_.x += dx;
    pRightUpper_.y += dy;
    pLeftLower_.x += dx;
    pLeftLower_.y += dy;
  }

  void Rectangle::move(point_t p)
  {
    point_t center = getFrameRect().pos;
    double dx = p.x - center.x;
    double dy = p.y - center.y;
    move(dx, dy);
  }

  void Rectangle::scale(double k)
  {
    double newWidth = (pRightUpper_.x - pLeftLower_.x) * k;
    double newHeigth = (pRightUpper_.y - pLeftLower_.y) * k;
    point_t center = getFrameRect().pos;
    pRightUpper_.x = center.x + newWidth / 2;
    pRightUpper_.y = center.y + newHeigth / 2;
    pLeftLower_.x = center.x - newWidth / 2;
    pLeftLower_.y = center.y - newWidth / 2;
  }
}
