#include "square.hpp"
#include <cmath>
#include <stdexcept>
#include "supportFunctions.hpp"

asafov::Square::Square(point_t lb, double side):
  lb_(lb),
  side_(side)
{
  if (side <= 0.0)
  {
    throw std::logic_error("incorrect figure");
  }
}

double asafov::Square::getArea() const
{
  return side_ * side_;
}

asafov::rectangle_t asafov::Square::getFrameRect() const
{
  double x = lb_.x + side_ / 2.0;
  double y = lb_.y + side_ / 2.0;
  rectangle_t rect = { side_, side_, { x, y } };
  return rect;
}

void asafov::Square::move(double dx, double dy)
{
  increaseDelta(lb_, dx, dy);
}

void asafov::Square::move(point_t pos)
{
  move(pos.x - (lb_.x + (side_ / 2.0)), pos.y - (lb_.y + (side_ / 2.0)));
}

void asafov::Square::doUnsafeScale(double k)
{
  rectangle_t rect = getFrameRect();
  scalePoint(lb_, rect.pos, k);
  side_ *= k;
}
