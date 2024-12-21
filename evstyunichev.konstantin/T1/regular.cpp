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

evstyunichev::Regular::Regular(point_t A, point_t B, point_t C):
  A_(A), B_(B), C_(C)
{
}

double evstyunichev::Regular::getArea() const
{
  double a = findDist(A_, B_), b = findDist(B_, C_), c = findDist(A_, C_);
  double p = (a + b + c) / 2.0;
  double ans = std::sqrt(p * (p - a) * (p - b) * (p - c));
  return ans;
}

evstyunichev::rectangle_t evstyunichev::Regular::getFrameRect() const
{
  rectangle_t frame;
  frame.pos = A_;
  double l = A_.x, r = A_.x, u = A_.y, d = A_.y;
  l = std::min(std::min(l, B_.x), C_.x);
  r = std::max(std::max(r, B_.x), C_.x);
  d = std::min(std::min(d, B_.y), C_.y);
  u = std::max(std::max(u, B_.y), C_.y);
  frame.height = std::max(u - A_.y, A_.y - d) * 2.0;
  frame.width = std::max(r - A_.x, A_.x - l) * 2.0;
  return frame;
}

void evstyunichev::Regular::move(double dx, double dy)
{
  A_.x += dx;
  A_.y += dy;
  B_.x += dx;
  B_.y += dy;
  C_.x += dx;
  C_.y += dy;
  return;
}

void evstyunichev::Regular::move(point_t cds)
{
  point_t mid = A_;
  move(cds.x - mid.x, cds.y - mid.y);
  return;
}

void evstyunichev::Regular::scale(double k)
{
  point_t b{(B_.x - A_.x) * k, (B_.y - A_.y) * k}, c{(C_.x - A_.x) * k, (C_.y - A_.y) * k};
  B_ = {A_.x + b.x, A_.y + b.y};
  C_ = {A_.x + c.x, A_.y + c.y};
  return;
}
