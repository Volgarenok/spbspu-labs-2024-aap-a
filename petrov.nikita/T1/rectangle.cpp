#include "rectangle.hpp"
#include "base-types.hpp"
#include <stdexcept>
#include <cmath>
petrov::Rectangle::Rectangle(petrov::point_t p1, petrov::point_t p2):
  p1_(p1),
  p2_(p2)
{
  if (p1_.x >= p2_.x || p1_.y >= p2_.y)
  {
    throw std::invalid_argument("NOTE: Scaling of some figures skipped due to their invalid description\n");
  }
}

double petrov::Rectangle::getArea() const
{
  return std::abs(p2_.x - p1_.x) * std::abs(p2_.y - p1_.y);
}

petrov::rectangle_t petrov::Rectangle::getFrameRect() const
{
  rectangle_t frame_rect = {};
  frame_rect.height = std::abs(p2_.y - p1_.y);
  frame_rect.width = std::abs(p2_.x - p1_.x);
  frame_rect.pos = { ((2 * p1_.x + p2_.x - p1_.x) / 2.0), ((2 * p1_.y + p2_.y - p1_.y) / 2.0) };
  return frame_rect;
}

void petrov::Rectangle::move(petrov::point_t concrete_point)
{
  rectangle_t frame_rect = getFrameRect();
  double dx = concrete_point.x - frame_rect.pos.x;
  double dy = concrete_point.y - frame_rect.pos.y;
  this->move(dx, dy);
}

void petrov::Rectangle::move(double dx, double dy)
{
  p1_.x += dx;
  p1_.y += dy;
  p2_.x += dx;
  p2_.y += dy;
}

void petrov::Rectangle::scale(double k)
{
  rectangle_t frame_rect = getFrameRect();
  p1_.x = frame_rect.pos.x + (p1_.x - frame_rect.pos.x) * k;
  p1_.y = frame_rect.pos.y + (p1_.y - frame_rect.pos.y) * k;
  p2_.x = frame_rect.pos.x + (p2_.x - frame_rect.pos.x) * k;
  p2_.y = frame_rect.pos.y + (p2_.y - frame_rect.pos.y) * k;
}

petrov::Shape * petrov::Rectangle::clone() const
{
  return new Rectangle(*this);
}
