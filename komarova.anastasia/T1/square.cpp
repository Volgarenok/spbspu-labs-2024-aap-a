#include "square.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "shape.hpp"

komarova::Square::Square(point_t low_left, double len) :
  low_left_(low_left),
  len_(len)
{
  if (len_ <= 0.0)
  {
    throw std::logic_error("incorrect len");
  }
}
double komarova::Square::getArea() const
{
  return (len_ * len_);
}
komarova::rectangle_t komarova::Square::getFrameRect() const
{
  return {len_, len_, {low_left_.x + (len_ / 2), low_left_.y + (len_ / 2)}};
}
void komarova::Square::move(point_t point)
{
  point_t center = getFrameRect().pos;
  double dx = point.x - center.x;
  double dy = point.y - center.y;
  move(dx, dy);
}
void komarova::Square::move(double dx, double dy)
{
  low_left_.x = low_left_.x + dx;
  low_left_.y = low_left_.y + dy;
}
void komarova::Square::scale(double coef)
{
  if (coef <= 0)
  {
    throw std::logic_error("incorrect coef");
  }
  low_left_.x -= (len_ * coef - len_) / 2;
  low_left_.y -= (len_ * coef - len_) / 2;
  len_ *= coef;
}
