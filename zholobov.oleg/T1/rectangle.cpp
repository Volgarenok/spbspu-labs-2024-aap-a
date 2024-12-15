#include "rectangle.hpp"

zholobov::Rectangle::Rectangle():
  rect_{}
{}

zholobov::Rectangle::Rectangle(const point_t& a, const point_t& c)
{
  rect_.width = c.x - a.x;
  rect_.height = c.y - a.y;
  rect_.pos.x = (a.x + c.x) / 2.0f;
  rect_.pos.y = (a.y + c.y) / 2.0f;
}

double zholobov::Rectangle::getArea()
{
  return rect_.width * rect_.height;
}

zholobov::rectangle_t zholobov::Rectangle::getFrameRect()
{
  return rect_;
}

void zholobov::Rectangle::move(point_t p)
{
  rect_.pos = p;
}

void zholobov::Rectangle::move(double dx, double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void zholobov::Rectangle::scale(double k)
{
  rect_.width *= k;
  rect_.height *= k;
}
