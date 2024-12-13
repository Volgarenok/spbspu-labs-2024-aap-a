#include "triangle.hpp"
#include <cmath>
double Triangle::getArea()
{
  double len_x1 = x1_.x - x2_.x;
  double len_y1 = x1_.y - x2_.y;
  double len_1 = std::sqrt(len_x1 * len_x1 + len_y1 * len_y1);
  double len_x2 = x2_.x - x3_.x;
  double len_y2 = x2_.y - x3_.y;
  double len_2 = std::sqrt(len_x2 * len_x2 + len_y2 * len_y2);
  double len_x3 = x3_.x - x1_.x;
  double len_y3 = x3_.y - x1_.y;
  double len_3 = std::sqrt(len_x3 * len_x3 + len_y3 * len_y3);
  double p = (len_1 + len_2 + len_3)/2;
  return std::sqrt(p * (p - len_1) * (p - len_2) * (p - len_3));
}

rectangle_t Triangle::getFrameRect()
{
  double x_max = 0;
  double x_min = 0;
  double y_max = 0;
  double y_min = 0;
  if (std::fmax(x1_.x, x2_.x) > x3_.x)
  {
    x_max = std::fmax(x1_.x, x2_.x);
  }
  else
  {
    x_max = x3_.x;
  }
  if (std::fmin(x1_.x, x2_.x) < x3_.x)
  {
    x_min = std::fmin(x1_.x, x2_.x);
  }
  else
  {
    x_min = x3_.x;
  }
  if (std::fmax(x1_.y, x2_.y) > x3_.y)
  {
    y_max = std::fmax(x1_.y, x2_.y);
  }
  else
  {
    y_max = x3_.y;
  }
  if (std::fmin(x1_.y, x2_.y) < x3_.y)
  {
    y_min = std::fmin(x1_.y, x2_.y);
  }
  else
  {
    y_min = x3_.y;
  }
  rectangle_t rect;
  rect.width = x_max - x_min;
  rect.height = y_max - y_min;
  rect.pos.x = x_min + (rect.width / 2);
  rect.pos.y = y_min + (rect.height / 2);
  return rect;
}

void Triangle::move(double x, double y)
{
  x1_.x += x;
  x1_.y += y;
  x3_.x += x;
  x3_.y += y;
  x2_.x += x;
  x2_.y += y;
}

void Triangle::move(point_t t)
{
  point_t centr = getFrameRect().pos;
  double shift_x = (t.x - centr.x);
  double shift_y = (t.y - centr.y);
  x2_.x += shift_x;
  x2_.y += shift_y;
  x3_.x += shift_x;
  x3_.y += shift_y;
  x1_.x += shift_x;
  x1_.y += shift_y;
}

//void Triangle::scale(point_t t, double k)
//{
//  double distance_x2 = x2_.x - t.x;
 // double distance_x4 = x4_.x - t.x;
//  double distance_y2 = x2_.y - t.y;
//  double distance_y4 = x2_.y - t.y;
  //x2_.x = t.x + distance_x2 * k;
 // x4_.x = t.x + distance_x4 * k;
 // x2_.y = t.y + distance_y2 * k;
 // x4_.y = t.y + distance_y4 * k;
//}
