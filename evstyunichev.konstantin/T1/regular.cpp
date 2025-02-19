#include "regular.hpp"
#include <cmath>
#include <iostream>
#include "base-types.hpp"

namespace
{
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
    return isInt(2.0 * M_PI / alpha) * alpha * 2.0;
  }
}

double evstyunichev::Regular::getBig() const
{
  return (a_ / 2.0) / std::cos((M_PI - alpha_) / 2.0);
}

double evstyunichev::Regular::getSmall() const
{
  return (a_ / 2.0) * std::tan((M_PI - alpha_) / 2.0);
}

evstyunichev::Regular::Regular(point_t A, point_t B, point_t C)
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
  alpha_ = alpha;
  a_ = b * 2.0;
  O_ = A;
}

double evstyunichev::Regular::getArea() const
{
  double ans = getSmall() * a_ * 2.0 * M_PI / alpha_;
  return ans;
}

evstyunichev::rectangle_t evstyunichev::Regular::getFrameRect() const
{
  double right = -1e9, left = 1e9, down = 1e9, up = -1e9, width = 0, height = 0;
  double R = getBig();
  point_t cur{};
  for (double angle = alpha_ / 2.0; !isEqual(angle, alpha_ / 2.0 + 2 * M_PI); angle += alpha_)
  {
    cur.x = O_.x + R * std::cos(angle);
    cur.y = O_.y + R * std::sin(angle);
    left = std::min(left, cur.x);
    right = std::max(right, cur.x);
    down = std::min(down, cur.y);
    up = std::max(up, cur.y);
  }
  height = up - down;
  width = right - left;
  rectangle_t temp{width, height, O_};
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
  O_ += cds;
  return;
}

void evstyunichev::Regular::scale(double k)
{
  a_ *= k;
  return;
}