#include "rectangle.hpp"
#include <stdexcept>

kizhin::Rectangle::Rectangle(const point_t& leftDown, const point_t& rightUp):
  data_{
    rightUp.x - leftDown.x,
    rightUp.y - leftDown.y,
    computePosition(leftDown, rightUp),
  }
{
  if (leftDown.x >= rightUp.x || leftDown.y >= rightUp.y) {
    throw std::logic_error("Invalid pointns to create rectangle");
  }
}

kizhin::rectangle_t kizhin::Rectangle::getFrameRect() const
{
  return data_;
}

double kizhin::Rectangle::getArea() const
{
  return data_.width * data_.height;
}

kizhin::Shape* kizhin::Rectangle::clone() const
{
  return new Rectangle(*this);
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

void kizhin::Rectangle::unsafeScale(double scalingFactor)
{
  data_.height *= scalingFactor;
  data_.width *= scalingFactor;
}

kizhin::point_t kizhin::Rectangle::computePosition(const point_t& leftDown,
    const point_t& rightUp)
{
  const point_t center{
    0.5 * (leftDown.x + rightUp.x),
    0.5 * (leftDown.y + rightUp.y),
  };
  return center;
}

