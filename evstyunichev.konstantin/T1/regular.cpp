#include "regular.hpp"
#include <cmath>
#include <cstddef>
#include <stdexcept>
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
  setBase();
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
  point_t leftDown = bestValue(1), rightUp = bestValue(0);
  rectangle_t temp{ rightUp.x - leftDown.x, rightUp.y - leftDown.y, middle_ };
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

double evstyunichev::Regular::bestAngle(double target) const
{
  double ans = 0;
  size_t l = 0, r = (2 * pi_v / alpha_);
  while (l <= r)
  {
    size_t mid = (l + r) / 2;
    if (base_ + mid * alpha_ <= target)
    {
      ans = base_ + mid * alpha_;
      l = mid + 1;
    }
    else
    {
      r = mid - 1;
    }
  }
  return ans;
}

evstyunichev::point_t evstyunichev::Regular::bestValue(bool is_smaller) const
{
  double a = middle_.x, b = middle_.y, angle = 0, R = get_R();
  if (is_smaller)
  {
    angle = bestAngle(pi_v);
    a += R * std::min(std::cos(angle), std::cos(angle + alpha_));
    angle = bestAngle(pi_v * 1.5);
    b += R * std::min(std::sin(angle), std::sin(angle + alpha_));
  }
  else
  {
    angle = bestAngle(0);
    a += R * std::max(std::cos(angle), std::cos(angle + alpha_));
    angle = bestAngle(pi_v / 2.0);
    b += R * std::max(std::sin(angle), std::sin(angle + alpha_));
  }
  return { a, b };
}

double evstyunichev::angle_check(double alpha)
{
  if (alpha <= 0)
  {
    throw std::invalid_argument("invalid argument!");
  }
  return is_int(2.0 * pi_v / alpha) * alpha * 2.0;
}

void evstyunichev::Regular::setBase()
{
  base_ -= std::ceil(base_ / alpha_) * alpha_;
  if (base_ > 0)
  {
    base_ -= alpha_;
  }
  return;
}
