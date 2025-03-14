#include "regular.hpp"
#include <cmath>
#include <iostream>
#include "base-types.hpp"
#include "spec_def.hpp"

double evstyunichev::Regular::get_R() const
{
  return (a_ / 2.0) / std::cos((pi_v - alpha_) / 2.0);
}

double evstyunichev::Regular::get_r() const
{
  return (a_ / 2.0) * std::tan((pi_v - alpha_) / 2.0);
}

evstyunichev::Regular::Regular(point_t A, double alpha, double a, double base):
  middle_(A),
  alpha_(alpha),
  a_(a),
  base_(base)
{
  if (!angle_check(alpha / 2.0) || (a <= 0))
  {
    throw std::invalid_argument("");
  }
}

evstyunichev::Regular::Regular(point_t middle, double r, size_t n):
  middle_(middle),
  alpha_(2.0 * pi_v / n),
  a_(std::sin(pi_v / n) * r * 2.0),
  base_(0)
{
  if ((r <= 0) || (n < 3))
  {
    throw std::invalid_argument("invalid arguments");
  }
}

double evstyunichev::Regular::getArea() const
{
  return get_r() * a_ * pi_v / alpha_;
}

evstyunichev::rectangle_t evstyunichev::Regular::getFrameRect() const
{
  double angle = base_, R = get_R(), left = middle_.x + R * std::cos(angle), right = left;
  double down = middle_.y + R * std::sin(angle), up = down, width = 0, height = 0;
  point_t cur{};
  for (double angle = base_; !is_equal(angle, base_ + 2 * pi_v); angle += alpha_)
  {
    cur.x = middle_.x + R * std::cos(angle);
    cur.y = middle_.y + R * std::sin(angle);
    left = std::min(left, cur.x);
    right = std::max(right, cur.x);
    down = std::min(down, cur.y);
    up = std::max(up, cur.y);
  }
  height = up - down;
  width = right - left;
  rectangle_t temp{width, height, middle_};
  return temp;
}

void evstyunichev::Regular::move(double dx, double dy)
{
  middle_.x += dx;
  middle_.y += dy;
  return;
}

void evstyunichev::Regular::move(point_t cds)
{
  move(cds.x - middle_.x, cds.y - middle_.y);
  return;
}

void evstyunichev::Regular::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("negative k!");
  }
  a_ *= k;
  return;
}

evstyunichev::point_t evstyunichev::Regular::getMiddle() const
{
  return middle_;
}

evstyunichev::Shape * evstyunichev::Regular::clone() const
{
  return new Regular(*this);
}

double evstyunichev::angle_check(double alpha)
{
  if (alpha <= 0)
  {
    throw std::invalid_argument("invalid argument!");
  }
  return is_int(2.0 * pi_v / alpha) * alpha * 2.0;
}
