#include "ring.hpp"
#include <cmath>
#include <iostream>
#include "base-types.hpp"

evstyunichev::Ring::Ring(point_t mid, double R, double r):
  interior_(mid, r, 48UL),
  external_(mid, R, 48UL)
{
  if (R <= r)
  {
    throw std::invalid_argument("R is not biiger than r");
  }
}

double evstyunichev::Ring::getArea() const
{
  double s = interior_.getArea() + external_.getArea();
  return s;
}

evstyunichev::rectangle_t evstyunichev::Ring::getFrameRect() const
{
  rectangle_t ans{};
  ans.pos = interior_.getMid();
  ans.height = 2 * external_.getBig();
  ans.width = 2 * external_.getBig();
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
