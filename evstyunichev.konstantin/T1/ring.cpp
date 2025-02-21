#include "ring.hpp"
#include <iostream>
#include "base-types.hpp"

constexpr double pi_v = 3.141592653589793238462643;

evstyunichev::Ring::Ring(point_t middle, double R, double r):
  interior_(middle, r, 48UL),
  external_(middle, R, 49UL)
{
  if (R <= r)
  {
    throw std::invalid_argument("R is not biiger than r");
  }
}

double evstyunichev::Ring::getArea() const
{
  double R = external_.get_R(), r = interior_.get_R();
  double s = R * R * pi_v - r * r * pi_v;
  return s;
}

evstyunichev::rectangle_t evstyunichev::Ring::getFrameRect() const
{
  rectangle_t ans{};
  ans.pos = interior_.getMiddle();
  ans.height = 2 * external_.get_R();
  ans.width = 2 * external_.get_R();
  return ans;
}

void evstyunichev::Ring::move(double dx, double dy)
{
  interior_.move(dx, dy);
  external_.move(dx, dy);
  return;
}

void evstyunichev::Ring::move(point_t target)
{
  interior_.move(target);
  external_.move(target);
  return;
}

void evstyunichev::Ring::scale(double k)
{
  interior_.scale(k);
  external_.scale(k);
  return;
}
