#include "rectangle.hpp"
#include "base-types.hpp"
#include <cmath>
petrov::Rectangle::Rectangle(petrov::point_t p1, petrov::point_t p2):
  p1_(p1),
  p3_(p2)
{
  if (p1.x >= p2.x || p1.y >= p2.y)
  {
    throw "NOTE: Scaling of some figures skipped due to their invalid description\n";
  }
  p2_.x = p1_.x;
  p2_.y = p3_.y;
  p4_.x = p3_.x;
  p4_.y = p1_.y;
}

double petrov::Rectangle::getArea() const
{
  return std::abs(p3_.x - p1_.x) * std::abs(p3_.y - p1_.y);
}

petrov::rectangle_t petrov::Rectangle::getFrameRect() const
{
  rectangle_t frame_rect = {};
  frame_rect.height = std::abs(p3_.y - p1_.y);
  frame_rect.width = std::abs(p3_.x - p1_.x);
  frame_rect.pos = { ((2 * p1_.x + p3_.x - p1_.x) / 2.0), ((2 * p1_.y + p3_.y - p1_.y) / 2.0) };
  return frame_rect;
}

void petrov::Rectangle::move(petrov::point_t concrete_point)
{
  rectangle_t frame_rect = getFrameRect();
  double dx = concrete_point.x - frame_rect.pos.x;
  double dy = concrete_point.y - frame_rect.pos.y;
  p1_.x += dx;
  p1_.y += dy;
  p2_.x += dx;
  p2_.y += dy;
  p3_.x += dx;
  p3_.y += dy;
  p4_.x += dx;
  p4_.y += dy;
}

void petrov::Rectangle::move(double dx, double dy)
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

void petrov::Rectangle::scale(double k)
{
  rectangle_t frame_rect = getFrameRect();
  double dx = (frame_rect.width / 2) * std::abs((k - 1));
  double dy = (frame_rect.height / 2) * std::abs((k - 1));
  p1_.x -= dx;
  p1_.y -= dy;
  p2_.x -= dx;
  p2_.y += dy;
  p3_.x += dx;
  p3_.y += dy;
  p4_.x += dx;
  p4_.y -= dy;
}
