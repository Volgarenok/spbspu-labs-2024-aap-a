#include "square.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "shape.hpp"

komarova::Square::Square(point_t low_left, double len) :
  //low_left_(low_left),
  //len_(len),
  rect_(low_left, {low_left.x + len, low_left.y + len})
{
  if (len <= 0.0)
  {
    throw std::logic_error("incorrect len");
  }
}
double komarova::Square::getArea() const
{
  return rect_.getArea();
  //return (len_ * len_);
}
komarova::rectangle_t komarova::Square::getFrameRect() const
{
  return rect_.getFrameRect();
  //return {len_, len_, {low_left_.x + (len_ / 2), low_left_.y + (len_ / 2)}};
}
void komarova::Square::move(point_t point)
{
  rect_.move(point);
  /*point_t center = getFrameRect().pos;
  double dx = point.x - center.x;
  double dy = point.y - center.y;
  move(dx, dy);*/
}
void komarova::Square::move(double dx, double dy)
{
  rect_.move(dx, dy);
  /*low_left_.x = low_left_.x + dx;
  low_left_.y = low_left_.y + dy;*/
}
void komarova::Square::scale(double coef)
{
  if (coef <= 0)
  {
    throw std::logic_error("incorrect coef");
  }
  rect_.scale(coef);
  /*low_left_.x -= (len_ * coef - len_) / 2;
  low_left_.y -= (len_ * coef - len_) / 2;
  len_ *= coef;*/
}
