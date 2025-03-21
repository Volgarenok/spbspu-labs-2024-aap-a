#include "rectangle.hpp"
#include "base-types.hpp"

evstyunichev::Rectangle::Rectangle(point_t leftDown, point_t rightUp):
  leftDown_(leftDown),
  rightUp_(rightUp)
{
  if ((leftDown.x >= rightUp.x) || (leftDown.y >= rightUp.y))
  {
    throw std::invalid_argument("invalid coordinates");
  }
}

double evstyunichev::Rectangle::getArea() const
{
  return (rightUp_.x - leftDown_.x) * (rightUp_.y - leftDown_.y);
}

evstyunichev::rectangle_t evstyunichev::Rectangle::getFrameRect() const
{
  double width = rightUp_.x - leftDown_.x, height = rightUp_.y - leftDown_.y;
  point_t pos = getMiddle();
  return rectangle_t{width, height, pos};
}

void evstyunichev::Rectangle::move(double dx, double dy)
{
  point_t d{dx, dy};
  leftDown_ += d;
  rightUp_ += d;
  return;
}

void evstyunichev::Rectangle::move(point_t cds)
{
  point_t mid = getMiddle();
  move(cds.x - mid.x, cds.y - mid.y);
  return;
}

evstyunichev::point_t evstyunichev::Rectangle::getMiddle() const
{
  point_t mid{};
  mid.x = (rightUp_.x + leftDown_.x) / 2.0;
  mid.y = (rightUp_.y + leftDown_.y) / 2.0;
  return mid;
}

void evstyunichev::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("negative k!");
  }
  point_t mid = getMiddle();
  double w = (rightUp_.x - leftDown_.x) * k, h = (rightUp_.y - leftDown_.y) * k;
  leftDown_.x = mid.x - w / 2.0;
  rightUp_.x = mid.x + w / 2.0;
  leftDown_.y = mid.y - h / 2.0;
  rightUp_.y = mid.y + h / 2.0;
  return;
}

evstyunichev::Shape * evstyunichev::Rectangle::clone() const
{
  return new Rectangle(*this);
}
