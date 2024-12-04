#include "rectangle.hpp"

abramov::Rectangle::Rectangle(double x1, double y1, double x2, double y2)
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

double abramov::Rectangle::getArea()
{
  return (pRightUpper.x - pLeftLower.x) * (pRightUpper.y - pLeftLower.y);
}

rectangle_t abramov::Rectangle::getFrameRect()
{
  double width = pRightUpper.x - pLeftLower.x;
  double height = pRightUpper.y - pLeftLower.y;
  double x = (pRightUpper.x + pLeftLower.x) / 2;
  double y = (pRightUpper.y + pLeftLower.y) / 2;
  point_t pos = point_t(x, y);
  return rectangle_t(x, y, pos);
}

void abramov::Rectangle::Move(double dx, double dy)
{
  pRightUpper.x += dx;
  pRightUpper.y += dy;
  pLeftLower.x += dx;
  pLeftLower.y += dy;
}

void abramov::Rectangle::Move(point_t p)
{
  rectangle_t frame_rect = getFrameRect();
  point_t center = frame_rect.pos;
  double dx = p.x - center.x;
  double dy = p.y - center.y;
  move(dx, dy);
}

void abramov::Rectangle::Scale(double k)
{
  
}
