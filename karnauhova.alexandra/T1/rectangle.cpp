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
  rectangle_t rect;
  rect.width = x2_.x - x4_.x;
  rect.height = x2_.y - x4_.y;
  rect.pos.x = x4_.x + (rect.width / 2);
  rect.pos.y = x4_.y + (rect.height / 2);
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
  x2_.x += (t.x - centr.x);
  x2_.y += (t.y - centr.y);
  x4_.x += (t.x - centr.x);
  x4_.y += (t.y - centr.y);
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
