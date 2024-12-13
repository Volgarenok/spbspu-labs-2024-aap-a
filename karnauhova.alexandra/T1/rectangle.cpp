#include "rectangle.hpp"
double Rectangle::getArea()
{
  double len1 = x2_.y - x4_.y;
  double len2 = x2_.x - x4_.x;
  return (len1 * len2);
}

rectangle_t Rectangle::getFrameRect()
{
  rectangle_t rect;
  rect.width = x2_.x - x4_.x;
  rect.height = x2_.y - x4_.y;
  rect.pos.x = x4_.x + (rect.width / 2);
  rect.pos.y = x4_.y + (rect.height / 2);
  return rect;
}

void Rectangle::move(double x, double y)
{
  x4_.x += x;
  x4_.y += y;
  x2_.x += x;
  x2_.y += y;
}

void Rectangle::move(point_t t)
{
  point_t centr = getFrameRect().pos;
  x2_.x += (t.x - centr.x);
  x2_.y += (t.y - centr.y);
  x4_.x += (t.x - centr.x);
  x4_.y += (t.y - centr.y);
}

void Rectangle::scale(point_t t, double k)
{
  double distance_x2 = x2_.x - t.x;
  double distance_x4 = x4_.x - t.x;
  double distance_y2 = x2_.y - t.y;
  double distance_y4 = x4_.y - t.y;
  x2_.x = t.x + distance_x2 * k;
  x4_.x = t.x + distance_x4 * k;
  x2_.y = t.y + distance_y2 * k;
  x4_.y = t.y + distance_y4 * k;
}
