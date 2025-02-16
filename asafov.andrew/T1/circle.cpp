#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

using asafov::point_t;
using asafov::rectangle_t;

asafov::Circle::Circle(point_t center, double radius):
  center_(center),
  radius_(radius)
{}

double asafov::Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

rectangle_t asafov::Circle::getFrameRect() const
{
  rectangle_t frect;
  frect.pos = center_;
  frect.height = 2.0 * radius_;
  frect.width = 2.0 * radius_;
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
  rectangle_t rect = getFrameRect();
  center_.x += (center_.x - rect.pos.x) * (scale - 1);
  center_.y += (center_.y - rect.pos.y) * (scale - 1);
  radius_ *= scale;
}
