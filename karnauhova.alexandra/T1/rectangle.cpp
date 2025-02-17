#include "rectangle.hpp"
#include <stdexcept>
karnauhova::Rectangle::Rectangle(const point_t& x4, const point_t& x2):
  x2_(x2),
  x4_(x4)
{
  if (!((x2_.x > x4_.x) || (x2_.y > x4_.y)))
  {
    throw std::logic_error("It's not a rectangle");
  }
}

double karnauhova::Rectangle::getArea() const
{
  double len1 = x2_.y - x4_.y;
  double len2 = x2_.x - x4_.x;
  return (len1 * len2);
}

karnauhova::rectangle_t karnauhova::Rectangle::getFrameRect() const
{
  double width = x2_.x - x4_.x;
  double height = x2_.y - x4_.y;
  point_t pos{x4_.x + (width / 2), x4_.y + (height / 2)};
  rectangle_t rect{width, height, pos};
  return rect;
}

void karnauhova::Rectangle::move(double x, double y)
{
  x4_.x += x;
  x4_.y += y;
  x2_.x += x;
  x2_.y += y;
}

void karnauhova::Rectangle::move(const point_t& t)
{
  point_t centr = getFrameRect().pos;
  move((t.x - centr.x), (t.y - centr.y));
}

void karnauhova::Rectangle::scale(double k)
{
  point_t t = getFrameRect().pos;
  double distance_x2 = x2_.x - t.x;
  double distance_x4 = x4_.x - t.x;
  double distance_y2 = x2_.y - t.y;
  double distance_y4 = x4_.y - t.y;
  x2_.x = t.x + distance_x2 * k;
  x4_.x = t.x + distance_x4 * k;
  x2_.y = t.y + distance_y2 * k;
  x4_.y = t.y + distance_y4 * k;
}

karnauhova::Shape* karnauhova::Rectangle::clone() const
{
  return new Rectangle(*this);
}
