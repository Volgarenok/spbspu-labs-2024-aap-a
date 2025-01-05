#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"

lebedev::Rectangle::Rectangle(lebedev::point_t leftDown, lebedev::point_t rightUp):
  leftDown_(leftDown),
  rightUp_(rightUp)
{}
double lebedev::Rectangle::getArea() const
{
  double area = (rightUp_.x - leftDown_.x) * (rightUp_.y - leftDown_.y);
  return area;
}
lebedev::rectangle_t lebedev::Rectangle::getFrameRect() const
{
  double centreX = leftDown_.x + (rightUp_.x - leftDown_.x) / 2;
  double centreY = leftDown_.y + (rightUp_.y - leftDown_.y) / 2;
  return { rightUp_.x - leftDown_.x, rightUp_.y - leftDown_.y, { centreX, centreY } };
}

void lebedev::Rectangle::move(point_t p)
{
  point_t centre = this->getFrameRect().pos;
  double dx = p.x - centre.x;
  double dy = p.y - centre.y;
  leftDown_.x += dx;
  rightUp_.x += dx;
  leftDown_.y += dy;
  rightUp_.y += dy;
}

void lebedev::Rectangle::move(double dx, double dy)
{
  leftDown_.x += dx;
  rightUp_.x += dx;
  leftDown_.y += dy;
  rightUp_.y += dy;
}

void lebedev::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale coefficient!");
  }
  point_t centre = this->getFrameRect().pos;
  leftDown_.x = centre.x + (leftDown_.x - centre.x) * k;
  leftDown_.y = centre.y + (leftDown_.y - centre.y) * k;
  rightUp_.x = centre.x + (rightUp_.x - centre.x) * k;
  rightUp_.y = centre.y + (rightUp_.y - centre.y) * k;
}
