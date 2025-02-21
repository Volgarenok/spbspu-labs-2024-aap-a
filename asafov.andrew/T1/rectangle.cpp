#include "rectangle.hpp"
#include <cmath>
#include "supportFunctions.hpp"

asafov::Rectangle::Rectangle(point_t lb, point_t rt):
  lb_(lb),
  rt_(rt)
{}

double asafov::Rectangle::getArea() const
{
  return std::pow((lb_.x - rt_.x) * (lb_.x - rt_.x), 0.5) * std::pow((lb_.y - rt_.y) * (lb_.y - rt_.y), 0.5);
}

asafov::rectangle_t asafov::Rectangle::getFrameRect() const
{
  double height = rt_.y - lb_.y;
  double width = rt_.x - lb_.x;
  double x = lb_.x + (rt_.x - lb_.x) / 2.0;
  double y = lb_.y + (rt_.y - lb_.y) / 2.0;
  rectangle_t rect;
  rect.height = height;
  rect.width = width;
  rect.pos.x = x;
  rect.pos.y = y;
  return rect;
}

void asafov::Rectangle::move(double dx, double dy)
{
  lb_.x += dx;
  rt_.x += dx;
  lb_.y += dy;
  rt_.y += dy;
}

void asafov::Rectangle::move(point_t pos)
{
  rectangle_t rect = getFrameRect();
  move(pos.x - rect.pos.x, pos.y - rect.pos.y);
}

void asafov::Rectangle::scale(double scale)
{
  rectangle_t rect = getFrameRect();
  scalePoint(rt_, rect.pos, scale);
  scalePoint(lb_, rect.pos, scale);
}
