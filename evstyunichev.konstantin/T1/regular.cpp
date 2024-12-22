#include "regular.hpp"
#include <cmath>
#include <iostream>
#include "base-types.hpp"

double evstyunichev::findDist(evstyunichev::point_t A, evstyunichev::point_t B)
{
  double a = A.x - B.x, b = A.y - B.y;
  double ans = std::sqrt(a * a + b * b);
  return ans;
}

evstyunichev::Regular::Regular(point_t O, size_t n, double a):
  O_(O), n_(n), a_(a)
{
  r_ = a_ / (2 * std::tan(M_PI / n_));
  R_ = a_ / (2 * std::sin(M_PI / n_));
}

double evstyunichev::Regular::getArea() const
{
  double ans = r_ * a_ * n_ / 2.0;
  return ans;
}

evstyunichev::rectangle_t evstyunichev::Regular::getFrameRect() const
{
  rectangle_t temp{};
  double right = 0, left = 0, down = 0, up = 0, fragment = 2.0 * M_PI / n_, zero = 0;
  zero = -(M_PI + fragment) / 2.0;
  down = O_.y - r_;
  left = O_.x + R_ * std::cos(zero - (n_ / 4) * fragment);
  right = O_.x + R_ * std::cos(zero + (n_ / 4 + 1) * fragment);
  up = O_.y + R_ * std::sin(zero + (n_ / 2) * fragment);
  temp.pos = O_;
  temp.height = up - down;
  temp.width = right - left;
  return temp;
}

void evstyunichev::Regular::move(double dx, double dy)
{
  O_.x += dx;
  O_.y += dy;
  return;
}

void evstyunichev::Regular::move(point_t cds)
{
  move(cds.x - O_.x, cds.y - O_.y);
  return;
}

void evstyunichev::Regular::scale(double k)
{
  a_ *= k;
  r_ *= k;
  R_ *= k;
  return;
}
