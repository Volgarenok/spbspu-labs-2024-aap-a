#include "square.hpp"
#include <stdexcept>
#include "base-types.hpp"

komarova::Square::Square(point_t low_left, double len):
  rect_(low_left, { low_left.x + len, low_left.y + len })
{
  if (len <= 0.0)
  {
    throw std::logic_error("incorrect len");
  }
}
double komarova::Square::getArea() const
{
  return rect_.getArea();
}
komarova::rectangle_t komarova::Square::getFrameRect() const
{
  return rect_.getFrameRect();
}
void komarova::Square::move(point_t point)
{
  rect_.move(point);
}
void komarova::Square::move(double dx, double dy)
{
  rect_.move(dx, dy);
}
void komarova::Square::scaleUnsafe(double coef)
{
  rect_.scale(coef);
}
