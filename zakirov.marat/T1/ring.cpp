#include "ring.hpp"
#include "shape.hpp"
#include <cmath>
#include <stdexcept>

zakirov::Ring::Ring(point_t center, double ex_radius, double in_radius) :
  center_(center),
  ex_radius_(ex_radius),
  in_radius_(in_radius)
{
  if (in_radius >= ex_radius || in_radius <= 0 || ex_radius <= 0)
  {
    throw std::invalid_argument("Incorrect data");
  }
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
  сircumscribed.width = ex_radius_ * 2;
  сircumscribed.height = ex_radius_ * 2;
  сircumscribed.pos = center_;

  return сircumscribed;
}

void zakirov::Ring::move(point_t target)
{
  center_ = target;
}

void zakirov::Ring::move(double bias_x, double bias_y)
{
  center_.x += bias_x;
  center_.y += bias_y;
}

void zakirov::Ring::scale(double k)
{
  in_radius_ *= k;
  ex_radius_ *= k;
}
