#include "ring.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

using asafov::point_t;
using asafov::rectangle_t;

asafov::Ring::Ring(point_t center, double innerradius, double outerradius):
  center_(center),
  innerradius_(innerradius),
  outerradius_(outerradius)
{}

double asafov::Ring::getArea() const
{
  return M_PI * (outerradius_ * outerradius_ - innerradius_ * innerradius_);
}

rectangle_t asafov::Ring::getFrameRect() const
{
  rectangle_t rect;
  rect.height = outerradius_ * 2.0;
  rect.width = outerradius_ * 2.0;
  rect.pos = center_;
  return rect;
}

void asafov::Ring::move(double x, double y)
{
  center_.x += x;
  center_.y += y;
}

void asafov::Ring::move(point_t pos)
{
  center_ = pos;
}

void asafov::Ring::scale(double scale)
{
  rectangle_t rect = getFrameRect();
  center_.x += (center_.x - rect.pos.x) * (scale - 1);
  center_.y += (center_.y - rect.pos.y) * (scale - 1);
  innerradius_ *= scale;
  outerradius_ *= scale;
}
