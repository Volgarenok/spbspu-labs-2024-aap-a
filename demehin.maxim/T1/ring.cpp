#include "ring.hpp"
#include <stdexcept>

demehin::Ring::Ring(point_t center, double out_r, double in_r):
  center_(center),
  in_r_(in_r),
  out_r_(out_r)
{
  if (out_r <= in_r || out_r <= 0 || in_r <= 0)
  {
    throw std::logic_error("incorrect shape");
  }
}

double demehin::Ring::getArea() const
{
  constexpr double PI = 3.1415;
  return PI * (out_r_ * out_r_ - in_r_ * in_r_);
}

demehin::rectangle_t demehin::Ring::getFrameRect() const
{
  double width = 2 * out_r_;
  double height = 2 * out_r_;
  rectangle_t fr_rect;
  fr_rect.pos = center_;
  fr_rect.width = width;
  fr_rect.height = height;
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
