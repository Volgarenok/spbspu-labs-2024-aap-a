#include "circle.hpp"
#include "regular.hpp"

evstyunichev::Circle::Circle(point_t O, double r):
  data_(O, r, 147UL)
{
  if (r <= 0)
  {
    throw std::invalid_argument("invalid radius!");
  }
}

double evstyunichev::Circle::getArea() const
{
  return data_.getArea();
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
  if (k <= 0)
  {
    throw std::logic_error("negative k!");
  }
  data_.scale(k);
  return;
}

evstyunichev::Shape * evstyunichev::Circle::clone() const
{
  return new Circle(*this);
}
