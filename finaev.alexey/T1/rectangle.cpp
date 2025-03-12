#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"

finaev::Rectangle::Rectangle(point_t l, point_t r):
  leftDown_(l),
  rightUp_(r)
{
  if (l.x >= r.x || l.y >= r.y)
  {
    throw std::invalid_argument("Uncorrect argument");
  }
}

double finaev::Rectangle::getArea() const
{
  return (rightUp_.x - leftDown_.x) * (rightUp_.y - leftDown_.y);
}

finaev::rectangle_t finaev::Rectangle::getFrameRect() const
{
  double x = leftDown_.x + (rightUp_.x - leftDown_.x) / 2;
  double y = leftDown_.y + (rightUp_.y - leftDown_.y) / 2;
  double width = rightUp_.x - leftDown_.x;
  double height = rightUp_.y - leftDown_.y;
  return { { x, y }, width, height };
}

void finaev::Rectangle::move(double sx, double sy)
{
  leftDown_.x += sx;
  leftDown_.y += sy;
  rightUp_.x += sx;
  rightUp_.y += sy;
}

void finaev::Rectangle::move(point_t a)
{
  point_t t = getFrameRect().pos;
  double changeX = a.x - t.x;
  double changeY = a.y - t.y;
  this->move(changeX, changeY);
}

void finaev::Rectangle::scale(double k)
{
  point_t centre = getFrameRect().pos;
  leftDown_.x = (leftDown_.x - centre.x) * k + centre.x;
  rightUp_.x = (rightUp_.x - centre.x) * k + centre.x;
  leftDown_.y = (leftDown_.y - centre.y) * k + centre.y;
  rightUp_.y = (rightUp_.y - centre.y) * k + centre.y;
}

