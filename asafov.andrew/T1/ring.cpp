#include "ring.hpp"
#include <cmath>
#include <stdexcept>
#include "supportFunctions.hpp"

#define pi std::atan(1.0) * 4

asafov::Ring::Ring(point_t center, double innerradius, double outerradius):
  center_(center),
  innerradius_(innerradius),
  outerradius_(outerradius)
{
  if (innerradius <= 0.0 || outerradius <= 0.0 || innerradius >= outerradius)
  {
    throw std::logic_error("incorrect figure");
  }
}

double asafov::Ring::getArea() const
{
  return pi * (outerradius_ * outerradius_ - innerradius_ * innerradius_);
}

asafov::rectangle_t asafov::Ring::getFrameRect() const
{
  double height = outerradius_ * 2.0;
  double width = outerradius_ * 2.0;
  rectangle_t rect;
  rect.height = height;
  rect.width = width;
  rect.pos = center_;
  return rect;
}

void asafov::Ring::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void asafov::Ring::move(point_t pos)
{
  center_ = pos;
}

void asafov::Ring::scale(double scale)
{
  if (scale <= 0)
  {
    throw std::logic_error("incorrect scale");
  }
  rectangle_t rect = getFrameRect();
  scalePoint(center_, rect.pos, scale);
  innerradius_ *= scale;
  outerradius_ *= scale;
}
