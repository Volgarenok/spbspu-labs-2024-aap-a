#include "ring.hpp"
#include <cmath>
#include <iostream>
#include "base-types.hpp"

evstyunichev::Ring::Ring(point_t mid, double R, double r)
{
  if ((r > R) || (r <= 0))
  {
    throw std::invalid_argument("invalid");
  }
  mid_ = mid;
  R_ = R;
  r_ = r;
}

double evstyunichev::Ring::getArea() const
{
  double s = M_PI * R_ * R_ - M_PI * r_ * r_;
  return s;
}

evstyunichev::rectangle_t evstyunichev::Ring::getFrameRect() const
{
  rectangle_t ans{};
  ans.pos = mid_;
  ans.height = 2 * R_;
  ans.width = 2 * R_;
  return ans;
}

void evstyunichev::Ring::move(double dx, double dy)
{
  mid_.x += dx;
  mid_.y += dy;
  return;
}

void evstyunichev::Ring::move(point_t target)
{
  move(target.x - mid_.x, target.y - mid_.y);
  return;
}

void evstyunichev::Ring::scale(double k)
{
  r_ *= k;
  R_ *= k;
  return;
}
