#include "regular.hpp"
#include <cmath>
#include <iostream>
#include "base-types.hpp"

constexpr double pi_v = 3.141592653589793238462643;

namespace
{
  using evstyunichev::point_t;
  const double prec = 0.0000001;
  bool isEqual(double, double, double p = prec);
  bool isInt(double);
  double angleCheck(double);

  bool isEqual(double a, double b, double p)
  {
    if (std::abs(a - b) <= p)
    {
      return 1;
    }
    return 0;
  }

  bool isInt(double d)
  {
    return (std::abs(d - std::round(d)) <= prec);
  }

  double angleCheck(double alpha)
  {
    if (!alpha)
    {
      return 0;
    }
    return isInt(2.0 * pi_v / alpha) * alpha * 2.0;
  }
}

double * evstyunichev::createDataRegular(point_t A, point_t B, point_t C)
{
  double a = findDist(A, B), b = findDist(B, C), c = findDist(A, C);
  if (a > c)
  {
    std::swap(B, C);
    std::swap(a, c);
  }
  double alpha = angleCheck(std::acos(a / c));
  if (!isEqual(std::pow(c, 2), std::pow(a, 2) + std::pow(b, 2)) || (alpha == 0))
  {
    throw std::invalid_argument("invalid");
  }
  double *data = new double[5]{A.x, A.y, alpha, b * 2.0, std::acos((C.x - A.x) / c)};
  return data;
}

evstyunichev::Regular::Regular(double *data):
  middle_{data[0], data[1]},
  alpha_(data[2]),
  a_(data[3]),
  base_(data[4])
{
  if (data[2] == 0)
  {
    throw std::invalid_argument("bad angle!");
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

evstyunichev::Regular::Regular(point_t middle, double r, size_t n):
  middle_(middle),
  alpha_(2.0 * pi_v / n),
  a_(std::sin(alpha_ / 2.0) * r * 2.0),
  base_(0)
{
  if ((r <= 0) || (n < 3))
  {
    throw std::invalid_argument("invalid arguments");
  }
}

double evstyunichev::Regular::getArea() const
{
  double ans = get_r() * a_  * pi_v / alpha_;
  return ans;
}

evstyunichev::rectangle_t evstyunichev::Regular::getFrameRect() const
{
  double angle = base_, R = get_R(), left = middle_.x + R * std::cos(angle), right = left;
  double down = middle_.y + R * std::sin(angle), up = down, width = 0, height = 0;
  double R = get_R();
  point_t cur{};
  for (double angle = base_; !isEqual(angle, base_ + 2 * pi_v); angle += alpha_)
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
