#include "circle.hpp"
#include <cmath>
#include <iostream>
#include "regular.hpp"

evstyunichev::Circle::Circle(point_t O, double r):
  data_(O, r, 48UL)
{
  if (r <= 0)
  {
    throw std::invalid_argument("invalid");
  }
}

double evstyunichev::Circle::getArea() const
{
  double r = data_.getBig();
  double s = M_PI * r * r;
  return s;
}

evstyunichev::rectangle_t evstyunichev::Circle::getFrameRect() const
{
  return data_.getFrameRect();
}

void evstyunichev::Circle::move(double dx, double dy)
{
  data_.move(dx, dy);
  return;
}

void evstyunichev::Circle::move(point_t cds)
{
  data_.move(cds);
  return;
}

void evstyunichev::Circle::scale(double k)
{
  data_.scale(k);
  return;
}
