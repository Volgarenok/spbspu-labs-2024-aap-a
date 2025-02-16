#include "rectangle.hpp"
#include <stdexcept>

lanovenko::Rectangle::Rectangle(point_t p1, point_t p2):
  leftDown_(p1),
  rightUpper_(p2)
{
  if (leftDown_.x >= rightUpper_.x || leftDown_.y >= rightUpper_.y)
  {
    throw std::invalid_argument("Wrong Rectangle Parametrs");
  }
}

double lanovenko::Rectangle::getArea() const
{
  double width = rightUpper_.x - leftDown_.x;
  double height = rightUpper_.y - leftDown_.y;
  return width * height;
}

lanovenko::rectangle_t lanovenko::Rectangle::getFrameRect() const
{
  double width = rightUpper_.x - leftDown_.x;
  double height = rightUpper_.y - leftDown_.y;
  point_t center = { (rightUpper_.x + leftDown_.x) / 2.0, (rightUpper_.y + leftDown_.y) / 2.0 };
  return { width, height, center };
}

void lanovenko::Rectangle::move(point_t p)
{
  point_t center = { (rightUpper_.x + leftDown_.x) / 2.0, (rightUpper_.y + leftDown_.y) / 2.0 };
  double deltaX = p.x - center.x;
  double deltaY = p.y - center.y;
  center = p;
  move(deltaX, deltaY);
}

void lanovenko::Rectangle::move(double dx, double dy)
{
  point_t* points[2] = { &leftDown_, &rightUpper_ };
  for (size_t i = 0; i < 2; i++)
  {
    points[i]->x += dx;
    points[i]->y += dy;
  }
}

void lanovenko::Rectangle::unsafeScale(double k)
{
  double width = rightUpper_.x - leftDown_.x;
  double height = rightUpper_.y - leftDown_.y;
  double new_width = width * k;
  double new_height = height * k;
  double deltaX = (new_width - width) / 2.0;
  double deltaY = (new_height - height) / 2.0;
  rightUpper_.x += deltaX;
  rightUpper_.y += deltaY;
  leftDown_.x -= deltaX;
  leftDown_.y -= deltaY;
}
