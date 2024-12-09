#include "rectangle.hpp"
#include <cassert>

kizhin::Rectangle::Rectangle(double width, double height, point_t position) :
  data_ { width, height, position }
{
}

double kizhin::Rectangle::getArea() const
{
  return data_.width * data_.height;
}

kizhin::rectangle_t kizhin::Rectangle::getFrameRect() const
{
  return data_;
}

void kizhin::Rectangle::move(double dx, double dy)
{
  data_.pos.x += dx;
  data_.pos.y += dy;
}

void kizhin::Rectangle::move(const point_t& postition)
{
  data_.pos = postition;
}

void kizhin::Rectangle::scale(double scaleFactor)
{
  assert(scaleFactor > 0);
  data_.height *= scaleFactor;
  data_.width *= scaleFactor;
}
