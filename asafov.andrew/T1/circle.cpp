#include "circle.hpp"
#include <cmath>
#include <stdexcept>
#include "supportFunctions.hpp"

asafov::Circle::Circle(point_t center, double radius):
  center_(center),
  radius_(radius)
{
  if (radius <= 0)
  {
    throw std::logic_error("incorrect figure");
  }
}

double asafov::Circle::getArea() const
{
  return radius_ * radius_ * getPi();
}

asafov::rectangle_t asafov::Circle::getFrameRect() const
{
  double height = 2.0 * radius_;
  rectangle_t frect = { height, height, center_ };
  return frect;
}

void asafov::Circle::move(double dx, double dy)
{
  increaseDelta(center_, dx, dy);
}

void asafov::Circle::move(point_t pos)
{
  center_ = pos;
}

void asafov::Circle::unsafeScale(double k)
{
  rectangle_t rect = getFrameRect();
  scalePoint(center_, rect.pos, k);
  radius_ *= k;
}
