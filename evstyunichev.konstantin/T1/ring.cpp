#include "ring.hpp"
#include "base-types.hpp"

evstyunichev::Ring::Ring(point_t middle, double R, double r):
  interior_(middle, r, 148UL),
  external_(middle, R, 149UL)
{
  if (R <= r)
  {
    throw std::invalid_argument("R is not bigger than r");
  }
  else if (r <= 0)
  {
    throw std::invalid_argument("invalid radius!");
  }
}

double evstyunichev::Ring::getArea() const
{
  return external_.getArea() - interior_.getArea();
}

evstyunichev::rectangle_t evstyunichev::Ring::getFrameRect() const
{
  return external_.getFrameRect();
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

evstyunichev::Shape * evstyunichev::Ring::clone() const
{
  return new Ring(*this);
}
