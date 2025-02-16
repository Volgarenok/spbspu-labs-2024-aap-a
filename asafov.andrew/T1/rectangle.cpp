#include "rectangle.hpp"
#include <cmath>

using asafov::point_t;
using asafov::rectangle_t;

asafov::Rectangle::Rectangle(point_t lb, point_t rt):
  lb_(lb),
  rt_(rt)
{}

double asafov::Rectangle::getArea() const
{
  return std::pow((lb_.x - rt_.x) * (lb_.x - rt_.x), 0.5) * std::pow((lb_.y - rt_.y) * (lb_.y - rt_.y), 0.5);
}

rectangle_t asafov::Rectangle::getFrameRect() const
{
  rectangle_t rect;
  rect.height = rt_.y - lb_.y;
  rect.width = rt_.x - lb_.x;
  rect.pos.x = lb_.x + (rt_.x - lb_.x) / 2.0;
  rect.pos.y = lb_.y + (rt_.y - lb_.y) / 2.0;
  return rect;
}

void asafov::Rectangle::move(double x, double y)
{
  lb_.x += x;
  rt_.x += x;
  lb_.y += y;
  rt_.y += y;
}

void asafov::Rectangle::move(point_t pos)
{
  rectangle_t rect = getFrameRect();
  lb_.x += pos.x - rect.pos.x;
  rt_.x += pos.x - rect.pos.x;
  lb_.y += pos.y - rect.pos.y;
  rt_.y += pos.y - rect.pos.y;
}

void asafov::Rectangle::scale(double scale)
{
  rectangle_t rect = getFrameRect();
  rt_.x += (rt_.x - rect.pos.x) * (scale - 1.0);
  rt_.y += (rt_.y - rect.pos.y) * (scale - 1.0);
  lb_.x += (lb_.x - rect.pos.x) * (scale - 1.0);
  lb_.y += (lb_.y - rect.pos.y) * (scale - 1.0);
}
