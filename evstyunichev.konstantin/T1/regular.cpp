#include "regular.hpp"
#include <cmath>
#include <iostream>
#include "base-types.hpp"

constexpr double pi_v = 3.141592653589793238462643;

namespace
{
  using evstyunichev::point_t;
  using evstyunichev::findDist;
  const double prec = 0.0000001;
  bool is_equal(double, double, double p = prec);
  bool is_int(double);
  double angle_check(double);

  bool is_equal(double a, double b, double p)
  {
    if (std::abs(a - b) <= p)
    {
      return 1;
    }
    return 0;
  }

  bool is_int(double d)
  {
    return (std::abs(d - std::round(d)) <= prec);
  }

  double angle_check(double alpha)
  {
    if (alpha <= 0)
    {
      throw std::invalid_argument("invalid argument!");
    }
    return is_int(2.0 * pi_v / alpha) * alpha * 2.0;
  }

}

double evstyunichev::Regular::get_R() const
{
  return (a_ / 2.0) / std::cos((pi_v - alpha_) / 2.0);
}

double evstyunichev::Regular::get_r() const
{
  return (a_ / 2.0) * std::tan((pi_v - alpha_) / 2.0);
}

evstyunichev::Regular::Regular(point_t A, point_t B, point_t C):
  middle_(A),
  alpha_(0),
  a_(0),
  base_(0)
{
  double a = findDist(A, B), b = findDist(B, C), c = findDist(A, C);
  if (a > c)
  {
    std::swap(B, C);
    std::swap(a, c);
  }
  double alpha = angle_check(std::acos(a / c));
  if (!is_equal(std::pow(c, 2), std::pow(a, 2) + std::pow(b, 2)) || (alpha == 0))
  {
    throw std::invalid_argument("invalid");
  }
  alpha_ = alpha;
  a_ = b * 2.0;
  base_ = std::acos((C.x - A.x) / c);
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
