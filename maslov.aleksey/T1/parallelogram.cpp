#include "parallelogram.hpp"
#include <algorithm>

maslov::Parallelogram::Parallelogram(point_t first, point_t second, point_t third):
  first_(first),
  second_(second),
  third_(third),
  fourth_({first.x + third.x - second.x, first.y + third.y - second.y})
{}
double maslov::Parallelogram::getArea() const
{
  double heigth = getFrameRect().height;
  double width = std::abs(first_.x - second_.x);
  return heigth * width;
}
maslov::rectangle_t maslov::Parallelogram::getFrameRect() const
{
  double heigth = std::abs(first_.y - third_.y);
  double maxX = std::max(std::max(first_.x, second_.x), std::max(third_.x,fourth_.x));
  double minX = std::min(std::min(first_.x, second_.x), std::min(third_.x,fourth_.x));
  double width = maxX - minX;
  double centerX = (first_.x + second_.x + third_.x + fourth_.x) / 4.0;
  double centerY = (first_.y + second_.y + third_.y + fourth_.y) / 4.0;
  return {width, heigth, {centerX, centerY}};
}
void maslov::Parallelogram::move(point_t s)
{
  point_t center = getFrameRect().pos;
  double dx = s.x - center.x;
  double dy = s.y - center.y;
  first_ = {first_.x + dx, first_.y + dy};
  second_ = {second_.x + dx, second_.y + dy};
  third_ = {third_.x + dx, third_.y + dy};
  fourth_ = {fourth_.x + dx, fourth_.y + dy};
}
void maslov::Parallelogram::move(double dx, double dy)
{
  first_ = {first_.x + dx, first_.y + dy};
  second_ = {second_.x + dx, second_.y + dy};
  third_ = {third_.x + dx, third_.y + dy};
  fourth_ = {fourth_.x + dx, fourth_.y + dy};
}
void maslov::Parallelogram::scale(double k)
{
  point_t center = getFrameRect().pos;
  first_.x = center.x + (first_.x - center.x) * k;
  first_.y = center.y + (first_.y - center.y) * k;
  second_.x = center.x + (second_.x - center.x) * k;
  second_.y = center.y + (second_.y - center.y) * k;
  third_.x = center.x + (third_.x - center.x) * k;
  third_.y = center.y + (third_.y - center.y) * k;
  fourth_.x = center.x + (fourth_.x - center.x) * k;
  fourth_.y = center.y + (fourth_.y - center.y) * k;
}
