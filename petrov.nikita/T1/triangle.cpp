#include "triangle.hpp"
#include "base-types.hpp"
#include <cmath>
#include <stdexcept>
#include <algorithm>
petrov::Triangle::Triangle(petrov::point_t p1, petrov::point_t p2, petrov::point_t p3):
  p1_(p1),
  p2_(p2),
  p3_(p3)
{
  double a = std::sqrt(std::pow((p1_.x - p2_.x), 2) + std::pow((p1_.y - p2_.y), 2));
  double b = std::sqrt(std::pow((p3_.x - p2_.x), 2) + std::pow((p3_.y - p2_.y), 2));
  double c = std::sqrt(std::pow((p1_.x - p3_.x), 2) + std::pow((p1_.y - p3_.y), 2));
  if (a + b <= c || a + c <= b || b + c <= a)
  {
    throw std::invalid_argument("NOTE: Scaling of some figures skipped due to their invalid description\n");
  }
}

double petrov::Triangle::getArea() const
{
  double a = std::sqrt(std::pow((p1_.x - p2_.x), 2) + std::pow((p1_.y - p2_.y), 2));
  double b = std::sqrt(std::pow((p3_.x - p2_.x), 2) + std::pow((p3_.y - p2_.y), 2));
  double c = std::sqrt(std::pow((p1_.x - p3_.x), 2) + std::pow((p1_.y - p3_.y), 2));
  double p = (a + b + c) / 2;
  return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

petrov::rectangle_t petrov::Triangle::getFrameRect() const
{
  rectangle_t frame_rect = {};
  double xmax = std::max(std::max(p1_.x, p2_.x), p3_.x);
  double xmin = std::min(std::min(p1_.x, p2_.x), p3_.x);
  double ymax = std::max(std::max(p1_.y, p2_.y), p3_.y);
  double ymin = std::min(std::min(p1_.y, p2_.y), p3_.y);
  frame_rect.width = std::abs(xmax - xmin);
  frame_rect.height = std::abs(ymax - ymin);
  frame_rect.pos = { ((2 * xmin + xmax - xmin) / 2.0), ((2 * ymin + ymax - ymin) / 2.0) };
  return frame_rect;
}

void petrov::Triangle::move(petrov::point_t concrete_point)
{
  rectangle_t frame_rect = getFrameRect();
  double dx = concrete_point.x - frame_rect.pos.x;
  double dy = concrete_point.y - frame_rect.pos.y;
  this->move(dx, dy);
}

void petrov::Triangle::move(double dx, double dy)
{
  p1_.x += dx;
  p1_.y += dy;
  p2_.x += dx;
  p2_.y += dy;
  p3_.x += dx;
  p3_.y += dy;
}

void petrov::Triangle::scale(double k)
{
  rectangle_t frame_rect = getFrameRect();
  p1_.x = frame_rect.pos.x + (p1_.x - frame_rect.pos.x) * k;
  p1_.y = frame_rect.pos.y + (p1_.y - frame_rect.pos.y) * k;
  p2_.x = frame_rect.pos.x + (p2_.x - frame_rect.pos.x) * k;
  p2_.y = frame_rect.pos.y + (p2_.y - frame_rect.pos.y) * k;
  p3_.x = frame_rect.pos.x + (p3_.x - frame_rect.pos.x) * k;
  p3_.y = frame_rect.pos.y + (p3_.y - frame_rect.pos.y) * k;
}
