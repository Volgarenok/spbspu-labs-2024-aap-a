#include "square.hpp"
#include <cmath>

using asafov::point_t;
using asafov::rectangle_t;

asafov::Square::Square(point_t lb, double side):
  lb_(lb),
  side_(side)
{}

double asafov::Square::getArea() const
{
  return side_ * side_;
}

rectangle_t asafov::Square::getFrameRect() const
{
  rectangle_t rect;
  rect.height = side_;
  rect.width = side_;
  rect.pos.x = lb_.x + side_ / 2.0;
  rect.pos.y = lb_.y + side_ / 2.0;
  return rect;
}

void asafov::Square::move(double x, double y)
{
  lb_.x += x;
  lb_.y += y;
}

void asafov::Square::move(point_t pos)
{
  lb_.x += pos.x - (lb_.x + (side_ / 2.0));
  lb_.y += pos.y - (lb_.y + (side_ / 2.0));
}

void asafov::Square::scale(double scale)
{
  rectangle_t rect = getFrameRect();
  lb_.x += (lb_.x - rect.pos.x) * (scale - 1.0);
  lb_.y += (lb_.y - rect.pos.y) * (scale - 1.0);
  side_ *= scale;
}
