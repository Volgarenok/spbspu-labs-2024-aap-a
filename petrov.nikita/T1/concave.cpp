#include "concave.hpp"
#include "base-types.hpp"
#include <cmath>
#include <algorithm>
petrov::Concave::Concave(petrov::point_t p1, petrov::point_t p2, petrov::point_t p3, petrov::point_t p4):
  p1_(p1),
  p2_(p2),
  p3_(p3),
  p4_(p4)
{
  if ( (p1_.x == p4_.x && p1_.y == p4_.y) || (p2_.x == p4_.x && p2_.y == p4_.y) || (p3_.x == p4_.x && p3_.y == p4_.y) )
  {
    throw "ERROR: Invalid data somewhere";
  }
  double a = sqrt(pow((p1_.x - p2_.x), 2) + pow((p1_.y - p2_.y), 2));
  double b = sqrt(pow((p3_.x - p2_.x), 2) + pow((p3_.y - p2_.y), 2));
  double c = sqrt(pow((p1_.x - p3_.x), 2) + pow((p1_.y - p3_.y), 2));
  if (a + b <= c || a + c <= b || b + c <= a)
  {
    throw "ERROR: Invalid data somewhere";
  }
  double p = (a + b + c) / 2;
  double area_of_triangle = sqrt(p * (p - a) * (p - b) * (p - c));
  a = sqrt(pow((p2_.x - p3_.x), 2) + pow((p2_.y - p3_.y), 2));
  b = sqrt(pow((p3_.x - p4_.x), 2) + pow((p3_.y - p4_.y), 2));
  c = sqrt(pow((p2_.x - p4_.x), 2) + pow((p2_.y - p4_.y), 2));
  p = (a + b + c) / 2;
  double area_1 = sqrt(p * (p - a) * (p - b) * (p - c));
  a = sqrt(pow((p2_.x - p1_.x), 2) + pow((p2_.y - p1_.y), 2));
  b = sqrt(pow((p1_.x - p4_.x), 2) + pow((p1_.y - p4_.y), 2));
  c = sqrt(pow((p2_.x - p4_.x), 2) + pow((p2_.y - p4_.y), 2));
  p = (a + b + c) / 2;
  double area_2 = sqrt(p * (p - a) * (p - b) * (p - c));
  a = sqrt(pow((p3_.x - p1_.x), 2) + pow((p3_.y - p1_.y), 2));
  b = sqrt(pow((p1_.x - p4_.x), 2) + pow((p1_.y - p4_.y), 2));
  c = sqrt(pow((p3_.x - p4_.x), 2) + pow((p3_.y - p4_.y), 2));
  p = (a + b + c) / 2;
  double area_3 = sqrt(p * (p - a) * (p - b) * (p - c));
  if (round(area_of_triangle) / 10 != round(area_1 + area_2 + area_3) / 10)
  {
    throw "ERROR: Invalid data somewhere\n";
  }
  double xmax = std::max(std::max(p1_.x, p2_.x), p3_.x);
  double xmin = std::min(std::min(p1_.x, p2_.x), p3_.x);
  double ymax = std::max(std::max(p1_.y, p2_.y), p3_.y);
  double ymin = std::min(std::min(p1_.y, p2_.y), p3_.y);
  frame_rect_.width = abs(xmax - xmin);
  frame_rect_.height = abs(ymax - ymin);
  frame_rect_.pos = { ((2 * xmin + xmax - xmin) / 2.0), ((2 * ymin + ymax - ymin) / 2.0) };
}

double petrov::Concave::getArea() const // Here you can use variables more effictively (decrease initializations number)
{
  double a = sqrt(pow((p1_.x - p2_.x), 2) + pow((p1_.y - p2_.y), 2));
  double b = sqrt(pow((p3_.x - p2_.x), 2) + pow((p3_.y - p2_.y), 2));
  double c = sqrt(pow((p1_.x - p3_.x), 2) + pow((p1_.y - p3_.y), 2));
  double p = (a + b + c) / 2;
  double area_without_cave = sqrt(p * (p - a) * (p - b) * (p - c));
  a = sqrt(pow((p2_.x - p4_.x), 2) + pow((p2_.y - p4_.y), 2));
  c = sqrt(pow((p4_.x - p3_.x), 2) + pow((p4_.y - p3_.y), 2));
  p = (a + b + c) / 2;
  double area_of_cave = sqrt(p * (p - a) * (p - b) * (p - c));
  return area_without_cave - area_of_cave;
}

petrov::rectangle_t petrov::Concave::getFrameRect() const
{
  return frame_rect_;
}

void petrov::Concave::move(petrov::point_t concrete_point)
{
  double posdx = concrete_point.x - frame_rect_.pos.x;
  double posdy = concrete_point.y - frame_rect_.pos.y;
  p4_.x += posdx;
  p4_.y += posdy;
  frame_rect_.pos.x = concrete_point.x;
  frame_rect_.pos.y = concrete_point.y;
  p1_.x = frame_rect_.pos.x - (frame_rect_.width / 2);
  p1_.y = frame_rect_.pos.y - (frame_rect_.height / 2);
  p2_.x = frame_rect_.pos.x - (frame_rect_.width / 2);
  p2_.y = frame_rect_.pos.y + (frame_rect_.height / 2);
  p3_.x = frame_rect_.pos.x + (frame_rect_.width / 2);
  p3_.y = frame_rect_.pos.y + (frame_rect_.height / 2);
  double xmax = std::max(std::max(p1_.x, p2_.x), p3_.x);
  double xmin = std::min(std::min(p1_.x, p2_.x), p3_.x);
  double ymax = std::max(std::max(p1_.y, p2_.y), p3_.y);
  double ymin = std::min(std::min(p1_.y, p2_.y), p3_.y);
  frame_rect_.width = abs(xmax - xmin);
  frame_rect_.height = abs(ymax - ymin);
}

void petrov::Concave::move(double dx, double dy)
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
  double xmax = std::max(std::max(p1_.x, p2_.x), p3_.x);
  double xmin = std::min(std::min(p1_.x, p2_.x), p3_.x);
  double ymax = std::max(std::max(p1_.y, p2_.y), p3_.y);
  double ymin = std::min(std::min(p1_.y, p2_.y), p3_.y);
  frame_rect_.width = abs(xmax - xmin);
  frame_rect_.height = abs(ymax - ymin);
}

void petrov::Concave::scale(double k)
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
      frame_rect_.height *= k;
      frame_rect_.width *= k;
      double xmax = std::max(std::max(p1_.x, p2_.x), p3_.x);
      double xmin = std::min(std::min(p1_.x, p2_.x), p3_.x);
      double ymax = std::max(std::max(p1_.y, p2_.y), p3_.y);
      double ymin = std::min(std::min(p1_.y, p2_.y), p3_.y);
      frame_rect_.pos = { ((2 * xmin + xmax - xmin) / 2.0), ((2 * ymin + ymax - ymin) / 2.0) };
    }
    else
    {
      double dx = (frame_rect_.width * (1 - k)) / 2;
      double dy = (frame_rect_.height * (1 - k)) / 2;
      p1_.x += dx;
      p1_.y += dy;
      p2_.x += dx;
      p2_.y -= dy;
      p3_.x -= dx;
      p3_.y -= dy;
      frame_rect_.height *= k;
      frame_rect_.width *= k;
      double xmax = std::max(std::max(p1_.x, p2_.x), p3_.x);
      double xmin = std::min(std::min(p1_.x, p2_.x), p3_.x);
      double ymax = std::max(std::max(p1_.y, p2_.y), p3_.y);
      double ymin = std::min(std::min(p1_.y, p2_.y), p3_.y);
      frame_rect_.pos = { ((2 * xmin + xmax - xmin) / 2.0), ((2 * ymin + ymax - ymin) / 2.0) };
    }
  }
}
