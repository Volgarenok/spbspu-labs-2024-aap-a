#include "rectangle.hpp"
#include <cmath>
#include <stdexcept>
#include "supportFunctions.hpp"

asafov::Rectangle::Rectangle(point_t lb, point_t rt):
  lb_(lb),
  rt_(rt)
{
  if (lb.x > rt.x || lb.y > rt.y)
  {
    throw std::logic_error("incorrect figure");
  }
}

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
  rectangle_t rect = { width, height, { x, y } };
  return rect;
}

void asafov::Rectangle::move(double dx, double dy)
{
  increaseDelta(lb_, dx, dy);
  increaseDelta(rt_, dx, dy);
}

void asafov::Rectangle::move(point_t pos)
{
  rectangle_t rect = getFrameRect();
  move(pos.x - rect.pos.x, pos.y - rect.pos.y);
}

void asafov::Rectangle::doUnsafeScale(double k)
{
  rectangle_t rect = getFrameRect();
  scalePoint(rt_, rect.pos, k);
  scalePoint(lb_, rect.pos, k);
}
