#include "circle.hpp"
#include <cmath>
#include <iostream>

evstyunichev::Circle::Circle(point_t O, double r)
{
  if (r <= 0)
  {
    throw std::invalid_argument("invalid");
  }
  O_ = O;
  r_ = r;
}

double evstyunichev::Circle::getArea() const
{
  double s = M_PI * r_ * r_;
  return s;
}

evstyunichev::rectangle_t evstyunichev::Circle::getFrameRect() const
{
  rectangle_t ans{};
  ans.pos = O_;
  ans.height = 2 * r_;
  ans.width = 2 * r_;
  return ans;
}

void evstyunichev::Circle::move(double dx, double dy)
{
  O_.x += dx;
  O_.y += dy;
  return;
}

void evstyunichev::Circle::move(point_t cds)
{
  move(cds.x - O_.x, cds.y - O_.y);
  return;
}

void evstyunichev::Circle::scale(double k)
{
  r_ *= k;
  return;
}
