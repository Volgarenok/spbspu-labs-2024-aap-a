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

evstyunichev::Regular::Regular(point_t O, size_t n, double a, double base):
  O_(O), n_(n), a_(a), base_(base)
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
  temp.pos = O_;
  double right = -1e9, left = 1e9, down = 1e9, up = -1e9, fragment = 2.0 * M_PI / n_;
  point_t cur{};
  for (size_t i = 0; i < n_; i++)
  {
    cur.x = O_.x + R_ * std::cos(base_ + fragment * i);
    cur.y = O_.y + R_ * std::sin(base_ + fragment * i);
    left = std::min(left, cur.x);
    right = std::max(right, cur.x);
    down = std::min(down, cur.y);
    up = std::max(up, cur.y);
  }
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