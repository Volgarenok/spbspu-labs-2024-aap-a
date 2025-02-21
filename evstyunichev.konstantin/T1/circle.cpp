#include "circle.hpp"
#include <cmath>
#include <iostream>
#include "regular.hpp"

evstyunichev::Circle::Circle(point_t O, double r)
{
  if (r <= 0)
  {
    throw std::invalid_argument("invalid");
  }
  data = new Regular(O, r, 48);
}

double evstyunichev::Circle::getArea() const
{
  double r = data->getBig();
  double s = M_PI * r * r;
  return s;
}

evstyunichev::rectangle_t evstyunichev::Circle::getFrameRect() const
{
  rectangle_t ans{};
  double r = data->getBig();
  ans.pos = data->getMid();
  ans.height = 2 * r;
  ans.width = 2 * r;
  return ans;
}

void evstyunichev::Circle::move(double dx, double dy)
{
  data->move(dx, dy);
  return;
}

void evstyunichev::Circle::move(point_t cds)
{
  data->move(cds);
  return;
}

void evstyunichev::Circle::scale(double k)
{
  data->scale(k);
  return;
}
