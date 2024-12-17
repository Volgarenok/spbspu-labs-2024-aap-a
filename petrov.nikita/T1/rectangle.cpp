#include "rectangle.hpp"
#include "base-types.hpp"
#include <cmath>
petrov::Rectangle::Rectangle(petrov::point_t p1, petrov::point_t p2):
  p1_(p1),
  p3_(p2)
{
  if (p1.x >= p2.x || p1.y >= p2.y)
  {
    throw "ERROR: Invalid data somewhere\n";
  }
  p2_.x = p1_.x;
  p2_.y = p3_.y;
  p4_.x = p3_.x;
  p4_.y = p1_.y;
  frame_rect_.height = abs(p2_.y - p1_.y);
  frame_rect_.width = abs(p4_.x - p1_.x);
  frame_rect_.pos = { ((2 * p1_.x + p3_.x - p1_.x) / 2.0), ((2 * p1_.y + p3_.y - p1_.y) / 2.0) };
}

double petrov::Rectangle::getArea() const
{
  return frame_rect_.width * frame_rect_.height;
}

petrov::rectangle_t petrov::Rectangle::getFrameRect() const
{
  return frame_rect_;
}

void petrov::Rectangle::move(petrov::point_t concrete_point)
{
  double dx = concrete_point.x - frame_rect_.pos.x;
  double dy = concrete_point.y - frame_rect_.pos.x;
  frame_rect_.pos.x = concrete_point.x;
  frame_rect_.pos.y = concrete_point.y;
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
  frame_rect_.pos.x += dx;
  frame_rect_.pos.y += dy;
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
  {
    if (k > 1)
    {
      double dx = (frame_rect_.width / 2) * (k - 1);
      double dy = (frame_rect_.height / 2) * (k - 1);
      p1_.x -= dx;
      p1_.y -= dy;
      p2_.x -= dx;
      p2_.y += dy;
      p3_.x += dx;
      p3_.y += dy;
      p4_.x += dx;
      p4_.y -= dy;
      frame_rect_.height *= k;
      frame_rect_.width *= k;
      frame_rect_.pos = { ((2 * p1_.x + p3_.x - p1_.x) / 2.0), ((2 * p1_.y + p3_.y - p1_.y) / 2.0) };
    }
    else
    {
      double dx = (frame_rect_.width / 2) * (1 - k);
      double dy = (frame_rect_.height / 2) * (1 - k);
      p1_.x += dx;
      p1_.y += dy;
      p2_.x += dx;
      p2_.y -= dy;
      p3_.x -= dx;
      p3_.y -= dy;
      p4_.x -= dx;
      p4_.y += dy;
      frame_rect_.height *= k;
      frame_rect_.width *= k;
      frame_rect_.pos = { ((2 * p1_.x + p3_.x - p1_.x) / 2.0), ((2 * p1_.y + p3_.y - p1_.y) / 2.0) };
    }
  }
}
