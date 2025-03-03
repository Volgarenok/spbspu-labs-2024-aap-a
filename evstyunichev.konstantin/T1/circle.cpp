#include "circle.hpp"
#include <iostream>
#include "regular.hpp"

constexpr double pi_v = 3.141592653589793238462643;

evstyunichev::Circle::Circle(point_t O, double r):
  data_(O, r, 47UL)
{
  if (r <= 0)
  {
    throw std::invalid_argument("invalid radius!");
  }
}

double evstyunichev::Circle::getArea() const
{
  double R = data_.get_R();
  double s = R * R * pi_v;
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

evstyunichev::Shape * evstyunichev::Circle::clone() const
{
  return new Circle(*this);
}
