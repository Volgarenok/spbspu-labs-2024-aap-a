#include "concave.hpp"
#include <cmath>
#include <algorithm>
petrov::Concave::Concave(point_t p1, point_t p2, point_t p3, point_t p4):
  p1_(p1),
  p2_(p2),
  p3_(p3),
  p4_(p4)
{
  if ( (p1_.x == p4_.x && p1_.y == p4_.y) 
           || (p2_.x == p4_.x && p2_.y == p4_.y)
               || (p3_.x == p4_.x && p3_.y == p4_.y) )
  {
    throw "NOTE: Scaling of some figures skipped due to their invalid description\n";
  }
  double a = std::sqrt(std::pow((p1_.x - p2_.x), 2) + std::pow((p1_.y - p2_.y), 2));
  double b = std::sqrt(std::pow((p3_.x - p2_.x), 2) + std::pow((p3_.y - p2_.y), 2));
  double c = std::sqrt(std::pow((p1_.x - p3_.x), 2) + std::pow((p1_.y - p3_.y), 2));
  if (a + b <= c || a + c <= b || b + c <= a)
  {
    throw "NOTE: Scaling of some figures skipped due to their invalid description\n";
  }
  double p = (a + b + c) / 2;
  double area_of_triangle = std::sqrt(p * (p - a) * (p - b) * (p - c));
  double area_1 = getAreaOfComponent(p2_, p3_, p4_);
  double area_2 = getAreaOfComponent(p1_, p2_, p4_);
  double area_3 = getAreaOfComponent(p1_, p3_, p4_);
  if (std::round(area_of_triangle) / 10 != std::round(area_1 + area_2 + area_3) / 10)
  {
    throw "NOTE: Scaling of some figures skipped due to their invalid description\n";
  }
}

double petrov::Concave::getArea() const
{
  double area_without_cave = getAreaOfComponent(p1_, p2_, p3_);
  double area_of_cave = getAreaOfComponent(p2_, p3_, p4_);
  return area_without_cave - area_of_cave;
}

double petrov::Concave::getAreaOfComponent(point_t p1, point_t p2, point_t p3) const
{
  double a = std::sqrt(std::pow((p1.x - p2.x), 2) + std::pow((p1.y - p2.y), 2));
  double b = std::sqrt(std::pow((p3.x - p2.x), 2) + std::pow((p3.y - p2.y), 2));
  double c = std::sqrt(std::pow((p1.x - p3.x), 2) + std::pow((p1.y - p3.y), 2));
  double p = (a + b + c) / 2;
  return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

petrov::rectangle_t petrov::Concave::getFrameRect() const
{
  rectangle_t frame_rect = {};
  double xmax = std::max(std::max(p1_.x, p2_.x), p3_.x);
  double xmin = std::min(std::min(p1_.x, p2_.x), p3_.x);
  double ymax = std::max(std::max(p1_.y, p2_.y), p3_.y);
  double ymin = std::min(std::min(p1_.y, p2_.y), p3_.y);
  frame_rect.width = xmax - xmin;
  frame_rect.height = ymax - ymin;
  frame_rect.pos = { ((2 * xmin + xmax - xmin) / 2.0), ((2 * ymin + ymax - ymin) / 2.0) };
  return frame_rect;
}

void petrov::Concave::move(point_t concrete_point)
{
  rectangle_t frame_rect = getFrameRect();
  double dx = concrete_point.x - frame_rect.pos.x;
  double dy = concrete_point.y - frame_rect.pos.y;
  this->move(dx, dy);
}

void petrov::Concave::move(double dx, double dy)
{
  p1_.x += dx;
  p1_.y += dy;
  p2_.x += dx;
  p2_.y += dy;
  p3_.x += dx;
  p3_.y += dy;
  p4_.x += dx;
  p4_.y += dy;
}

void petrov::Concave::scale(double k)
{
  {
    rectangle_t frame_rect = getFrameRect();
    p1_.x = frame_rect.pos.x + (p1_.x - frame_rect.pos.x) * k;
    p1_.y = frame_rect.pos.y + (p1_.y - frame_rect.pos.y) * k;
    p2_.x = frame_rect.pos.x + (p2_.x - frame_rect.pos.x) * k;
    p2_.y = frame_rect.pos.y + (p2_.y - frame_rect.pos.y) * k;
    p3_.x = frame_rect.pos.x + (p3_.x - frame_rect.pos.x) * k;
    p3_.y = frame_rect.pos.y + (p3_.y - frame_rect.pos.y) * k;
    p4_.x = frame_rect.pos.x + (p4_.x - frame_rect.pos.x) * k;
    p4_.y = frame_rect.pos.y + (p4_.y - frame_rect.pos.y) * k;
  }
}
