#include "rectangle.hpp"

#include <stdexcept>
#include <algorithm>

rychkov::Rectangle::Rectangle(point_t center, double height, double width):
  center_(center),
  height_(height),
  width_(width)
{
  if((height == 0) || (width_ == 0))
  {
    throw std::invalid_argument("invalid rectangle");
  }
}
rychkov::Rectangle::Rectangle(point_t bottomLeft, point_t topRight):
  Rectangle({(bottomLeft.x + topRight.x) / 2, (bottomLeft.y + topRight.y) / 2},
      std::abs(bottomLeft.x - topRight.x),
      std::abs(bottomLeft.y - topRight.y))
{}

double rychkov::Rectangle::getArea() const noexcept
{
  return height_ * width_;
}
rychkov::rectangle_t rychkov::Rectangle::getFrameRect() const noexcept
{
  return {height_, width_, center_};
}
void rychkov::Rectangle::move(point_t destination) noexcept
{
  center_ = destination;
}
void rychkov::Rectangle::move(double deltaX, double deltaY) noexcept
{
  center_.x += deltaX;
  center_.y += deltaY;
}
void rychkov::Rectangle::scale(double coef)
{
  if (coef == 0)
  {
    throw std::invalid_argument("scale can't be executed with coefficient 0");
  }
  height_ *= coef;
  width_ *= coef;
}
