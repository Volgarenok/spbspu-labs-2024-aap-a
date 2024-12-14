#include "rectangle.hpp"

Rectangle::Rectangle()
  : rect_{}
{}

Rectangle::Rectangle(const point_t& a, const point_t& c)
{
  rect_.width = c.x - a.x;
  rect_.height = c.y - a.y;
  rect_.pos.x = (a.x + c.x) / 2.0f;
  rect_.pos.y = (a.y + c.y) / 2.0f;
}

float Rectangle::getArea()
{
  return rect_.width * rect_.height;
}

rectangle_t Rectangle::getFrameRect()
{
  return rect_;
}

void Rectangle::move(point_t p)
{
  rect_.pos = p;
}

void Rectangle::move(float dx, float dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void Rectangle::scale(float k)
{
  rect_.width *= k;
  rect_.height *= k;
}
