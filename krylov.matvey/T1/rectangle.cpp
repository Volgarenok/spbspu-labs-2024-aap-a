#include "rectangle.hpp"
#include <stdexcept>

krylov::Rectangle::Rectangle(const point_t& bottomLeft, const point_t& topRight):
  bottomLeft_(bottomLeft),
  topRight_(topRight)
{
  if (bottomLeft_.x >= topRight_.x || bottomLeft_.y >= topRight_.y)
  {
    throw std::invalid_argument("Invalid rectangle coordinates");
  }
}

double krylov::Rectangle::getArea() const
{
  return (topRight_.x - bottomLeft_.x) * (topRight_.y - bottomLeft_.y);
}

krylov::rectangle_t krylov::Rectangle::getFrameRect() const
{
  point_t rectangleCenter = {bottomLeft_.x + ((topRight_.x - bottomLeft_.x) / 2.0), bottomLeft_.y + ((topRight_.y - bottomLeft_.y) / 2.0)};
  return rectangle_t{(topRight_.x - bottomLeft_.x), (topRight_.y - bottomLeft_.y), rectangleCenter};
}

void krylov::Rectangle::move(const point_t& point)
{
  double dx = point.x - (bottomLeft_.x + topRight_.x) / 2.0;
  double dy = point.y - (bottomLeft_.y + topRight_.y) / 2.0;
  move(dx, dy);
}

void krylov::Rectangle::move(double dx, double dy)
{
  bottomLeft_.x += dx;
  bottomLeft_.y += dy;
  topRight_.x += dx;
  topRight_.y += dy;
}

void krylov::Rectangle::unsafeScale(double factor) noexcept
{
  point_t center = getFrameRect().pos;
  bottomLeft_.x = center.x + (bottomLeft_.x - center.x) * factor;
  bottomLeft_.y = center.y + (bottomLeft_.y - center.y) * factor;
  topRight_.x = center.x + (topRight_.x - center.x) * factor;
  topRight_.y = center.y + (topRight_.y - center.y) * factor;
}
