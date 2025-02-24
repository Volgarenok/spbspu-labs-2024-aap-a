#include "ring.hpp"
#include <cmath>
#include <stdexcept>
#include "supportFunctions.hpp"

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
  return pi() * (outerradius_ * outerradius_ - innerradius_ * innerradius_);
}

asafov::rectangle_t asafov::Ring::getFrameRect() const
{
  double side = outerradius_ * 2.0;
  rectangle_t rect{side, side, center_};
  return rect;
}

void asafov::Ring::move(double dx, double dy)
{
  increaseDelta(center_, dx, dy);
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
