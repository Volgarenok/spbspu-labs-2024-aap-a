#include "circle.hpp"
#include <cmath>
#include <iostream>

evstyunichev::Circle::Circle(point_t mid, double r):
  mid_(mid), r_(r)
{
}

double evstyunichev::Circle::getArea() const
{
  double s = M_PI * r_ * r_;
  return s;
}

evstyunichev::rectangle_t evstyunichev::Circle::getFrameRect() const
{
  rectangle_t ans{};
  ans.pos = mid_;
  ans.height = 2 * r_;
  ans.width = 2 * r_;
  return ans;
}

void evstyunichev::Circle::move(double dx, double dy)
{
  mid_.x += dx;
  mid_.y += dy;
  return;
}

void evstyunichev::Circle::move(point_t target)
{
  move(target.x - mid_.x, target.y - mid_.y);
  return;
}

void evstyunichev::Circle::scale(double k)
{
  r_ *= k;
  return;
}
