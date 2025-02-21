#include "ellipse.hpp"
#include <cmath>
#include "supportFunctions.hpp"

#define pi std::atan(1.0) * 4

asafov::Ellipse::Ellipse(point_t center, double verticalradius, double horizontalradius):
  center_(center),
  verticalradius_(verticalradius),
  horizontalradius_(horizontalradius)
{}

double asafov::Ellipse::getArea() const
{
  return pi * verticalradius_ * horizontalradius_;
}

asafov::rectangle_t asafov::Ellipse::getFrameRect() const
{
  double height = verticalradius_ * 2.0;
  double width = horizontalradius_ * 2.0;
  rectangle_t frect;
  frect.height = height;
  frect.width = width;
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
  scalePoint(center_, rect.pos, scale);
  verticalradius_ *= scale;
  horizontalradius_ *= scale;
}
