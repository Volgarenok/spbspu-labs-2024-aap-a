#include "triangle.hpp"
#include <iostream>
#include <cmath>
#include "base-types.hpp"

hismatova::triangle::triangle(point_t p1, point_t p2, point_t p3) :
  p1_(p1),
  p2_(p2),
  p3_(p3)
{}
hismatova::point_t hismatova::triangle::get_center() const
{
  return { (p1_.x + p2_.x + p3_.x) / 3, (p1_.y + p2_.y + p3_.y) / 3 };
}
double hismatova::triangle::getArea() const
{
  double a = std::sqrt(std::pow(p2_.x - p1_.x, 2) + std::pow(p2_.y - p1_.y, 2));
  double b = std::sqrt(std::pow(p3_.x - p2_.x, 2) + std::pow(p3_.y - p2_.y, 2));
  double c = std::sqrt(std::pow(p1_.x - p3_.x, 2) + std::pow(p1_.y - p3_.y, 2));
  double p = (a + b + c) / 2;
  return std::sqrt(p * (p - a) * (p - b) * (p - c));
}
void hismatova::triangle::move(double x, double y)
{
  p1_.x += x;
  p1_.y += y;
  p2_.x += x;
  p2_.y += y;
  p3_.x += x;
  p3_.y += y;
}
hismatova::rectangle_t hismatova::triangle::getFrameRect() const
{
  double minX = std::min({ p1_.x, p2_.x, p3_.x });
  double maxX = std::max({ p1_.x, p2_.x, p3_.x });
  double minY = std::min({ p1_.y, p2_.y, p3_.y });
  double maxY = std::max({ p1_.y, p2_.y, p3_.y });
  return { {(minX + maxX) / 2, (minY + maxY) / 2}, maxX - minX, maxY - minY };
}

void hismatova::triangle::move(point_t point)
{
  double dx = point.x - get_center().x;
  double dy = point.y - get_center().y;
  move(dx, dy);
}
void hismatova::triangle::scale(double index)
{
  if (index <= 0)
  {
    std::cerr << "index must be positive";
    return;
  }
  point_t center = get_center();
  p1_.x = center.x + index * (p1_.x - center.x);
  p1_.y = center.y + index * (p1_.y - center.y);
  p2_.x = center.x + index * (p2_.x - center.x);
  p2_.y = center.y + index * (p2_.y - center.y);
  p3_.x = center.x + index * (p3_.x - center.x);
  p3_.y = center.y + index * (p3_.y - center.y);
}
