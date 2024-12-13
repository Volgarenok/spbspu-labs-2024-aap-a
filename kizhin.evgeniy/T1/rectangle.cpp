#include "rectangle.hpp"
#include <cassert>

kizhin::Rectangle::Rectangle(double width, double height, const point_t& position) :
  data_ { width, height, position }
{
}

kizhin::rectangle_t kizhin::Rectangle::getFrameRect() const
{
  return data_;
}

double kizhin::Rectangle::getArea() const
{
  return data_.width * data_.height;
}

void kizhin::Rectangle::move(const point_t& newPos)
{
  data_.pos = newPos;
}

void kizhin::Rectangle::move(double dx, double dy)
{
  data_.pos.x += dx;
  data_.pos.y += dy;
}

void kizhin::Rectangle::scale(double scaleFactor)
{
  assert(scaleFactor > 0.0);
  data_.height *= scaleFactor;
  data_.width *= scaleFactor;
}

