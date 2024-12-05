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
    pLeftLower = p1;
    pRightUpper = p2;
  }

  double Rectangle::getArea() const
  {
    return (pRightUpper.x - pLeftLower.x) * (pRightUpper.y - pLeftLower.y);
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    double x = (pRightUpper.x + pLeftLower.x) / 2;
    double y = (pRightUpper.y + pLeftLower.y) / 2;
    point_t pos;
    pos.x = x;
    pos.y = y;
    rectangle_t frame_rect;
    frame_rect.width = x;
    frame_rect.height = y;
    frame_rect.pos = pos;
    return frame_rect;
  }

  void Rectangle::move(double dx, double dy)
  {
    pRightUpper.x += dx;
    pRightUpper.y += dy;
    pLeftLower.x += dx;
    pLeftLower.y += dy;
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
    double newWidth = (pRightUpper.x - pLeftLower.x) * k;
    double newHeigth = (pRightUpper.y - pLeftLower.y) * k;
    point_t center = getFrameRect().pos;
    pRightUpper.x = center.x + newWidth / 2;
    pRightUpper.y = center.y + newHeigth / 2;
    pLeftLower.x = center.x - newWidth / 2;
    pLeftLower.y = center.y - newWidth / 2;
  }

}
