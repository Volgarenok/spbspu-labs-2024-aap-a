#include "rectangle.hpp"
#include <stdexcept>
#include "shape.hpp"
#include "base-types.hpp"

namespace abramov
{
Rectangle::Rectangle(double x1, double y1, double x2, double y2)
{
  if (x1 >= x2 || y1 >= y2)
  {
    throw std::logic_error("Impossible to build a rectangle");
  }
  pLeftLower.x = x1;
  pLeftLower.y = y1;
  pRightUpper.x = x2;
  pRightUpper.y = y2;
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
  rectangle_t frame_rect = getFrameRect();
  point_t center = frame_rect.pos;
  double dx = p.x - center.x;
  double dy = p.y - center.y;
  move(dx, dy);
}

void Rectangle::scale(double k)
{
  k = 0;
}
}
