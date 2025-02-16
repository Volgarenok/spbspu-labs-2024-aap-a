#include "ellipse.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

using asafov::point_t;
using asafov::rectangle_t;

asafov::Ellipse::Ellipse(point_t center, double verticalradius, double horizontalradius):
  center_(center),
  verticalradius_(verticalradius),
  horizontalradius_(horizontalradius)
{}

double asafov::Ellipse::getArea() const
{
  return M_PI * verticalradius_ * horizontalradius_;
}

rectangle_t asafov::Ellipse::getFrameRect() const
{
  rectangle_t frect;
  frect.height = verticalradius_ * 2.0;
  frect.width = horizontalradius_ * 2.0;
  frect.pos = center_;
  return frect;
}

void asafov::Ellipse::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void asafov::Ellipse::move(point_t pos)
{
  center_ = pos;
}

void asafov::Ellipse::scale(double scale)
{
  rectangle_t rect = getFrameRect();
  center_.x += (center_.x - rect.pos.x) * (scale - 1);
  center_.y += (center_.y - rect.pos.y) * (scale - 1);
  verticalradius_ *= scale;
  horizontalradius_ *= scale;
}
