#include "rectangle.hpp"

maslevtsov::Rectangle::Rectangle(rectangle_t rect):
  rect_(rect)
{}

double maslevtsov::Rectangle::getArea()
{
  return rect_.width * rect_.height;
}

maslevtsov::rectangle_t maslevtsov::Rectangle::getFrameRect()
{
  rectangle_t frameRect;
  frameRect.width = (rect_.pos.x + rect_.width / 2) - (rect_.pos.x - rect_.width / 2);
  frameRect.height = (rect_.pos.y + rect_.height / 2) - (rect_.pos.y - rect_.height / 2);
  frameRect.pos.x = rect_.pos.x;
  frameRect.pos.y = rect_.pos.y;
  return frameRect;
}

void maslevtsov::Rectangle::move(point_t pnt)
{
  rect_.pos = pnt;
  rect_.pos = pnt;
}

void maslevtsov::Rectangle::move(double dx, double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void maslevtsov::Rectangle::scale(double k)
{
  rect_.width *= k;
  rect_.height *= k;
}
