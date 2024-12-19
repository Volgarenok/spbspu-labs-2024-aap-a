#include "ring.hpp"

demehin::Ring::Ring(double cent_x, double cent_y, double out_r, double in_r):
  in_r_(in_r), out_r_(out_r)
{
  center_.x = cent_x;
  center_.y = cent_y;
}

double demehin::Ring::getArea() const
{
  const double PI = 3.1415;
  return PI * (out_r_ * out_r_ - in_r_ * in_r_);
}

demehin::rectangle_t demehin::Ring::getFrameRect() const
{
  rectangle_t fr_rect;
  fr_rect.pos = center_;
  fr_rect.width = 2 * out_r_;
  fr_rect.height = 2 * out_r_;
  return fr_rect;
}

void demehin::Ring::move(point_t s)
{
  center_ = s;
}

void demehin::Ring::move(double x, double y)
{
  center_.x += x;
  center_.y += y;
}

void demehin::Ring::scale(double k)
{
  out_r_ *= k;
  in_r_ *= k;
}
