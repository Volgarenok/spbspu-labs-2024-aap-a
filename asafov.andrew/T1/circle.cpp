#include "circle.hpp"
#include <cmath>
#include "supportFunctions.hpp"

#define pi std::atan(1.0) * 4

asafov::Circle::Circle(point_t center, double radius):
  center_(center),
  radius_(radius)
{}

double asafov::Circle::getArea() const
{
  return radius_ * radius_ * pi;
}

asafov::rectangle_t asafov::Circle::getFrameRect() const
{
  double height = 2.0 * radius_;
  rectangle_t frect;
  frect.pos = center_;
  frect.height = height;
  frect.width = height;
  return frect;
}

void asafov::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void asafov::Circle::move(point_t pos)
{
  center_ = pos;
}

void asafov::Circle::scale(double scale)
{
  if (scale <= 0)
  {
    throw std::logic_error("incorect scale");
  }
  rectangle_t rect = getFrameRect();
  scalePoint(center_, rect.pos, scale);
  radius_ *= scale;
}
