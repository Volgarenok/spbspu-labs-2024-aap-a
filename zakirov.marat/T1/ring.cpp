#include "ring.hpp"
#include "shape.hpp"
#include <cmath>

zakirov::Ring::Ring(point_t center, double in_radius, double ex_radius) :
  center_(center),
  in_radius_(in_radius),
  ex_radius_(ex_radius)
{
}

double zakirov::Ring::getArea() const
{
  double in_area = 3.14 * pow(in_radius_, 2);
  double ex_area = 3.14 * pow(ex_radius_, 2);

  return ex_area - in_area;
}

zakirov::rectangle_t zakirov::Ring::getFrameRect() const
{
  rectangle_t сircumscribed;
  сircumscribed.width_ = ex_radius_;
  сircumscribed.height_ = ex_radius_;
  сircumscribed.position_ = center_;

  return сircumscribed;
}

void zakirov::Ring::move(point_t target)
{
  center_ = target;
}

void zakirov::Ring::move(double bias_x, double bias_y)
{
  center_.x_ += bias_x;
  center_.y_ += bias_y;
}

void zakirov::Ring::scale(double k)
{
  in_radius_ *= k;
  ex_radius_ *= k;
}
