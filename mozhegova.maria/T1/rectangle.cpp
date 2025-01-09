#include "rectangle.hpp"
#include <stdexcept>

mozhegova::Rectangle::Rectangle(point_t lowLef, point_t uppRig):
  lowerLeft_(lowLef),
  upperRight_(uppRig)
{
  if (lowLef.x >= uppRig.x || lowLef.y >= uppRig.y)
  {
    throw std::invalid_argument("Incorrect coordinates");
  }
}

double mozhegova::Rectangle::getArea() const
{
  double width = upperRight_.x - lowerLeft_.x;
  double height = upperRight_.y - lowerLeft_.y;
  return width * height;
}

mozhegova::rectangle_t mozhegova::Rectangle::getFrameRect() const
{
  double width = upperRight_.x - lowerLeft_.x;
  double height = upperRight_.y - lowerLeft_.y;
  double x_ = lowerLeft_.x + (width / 2.0);
  double y_ = lowerLeft_.y + (height / 2.0);
  return {width, height, {x_, y_}};
}

void mozhegova::Rectangle::move(point_t p)
{
  point_t center = getFrameRect().pos;
  double dx = p.x - center.x;
  double dy = p.y - center.y;
  lowerLeft_ = {lowerLeft_.x + dx, lowerLeft_.y + dy};
  upperRight_ = {upperRight_.x + dx, upperRight_.y + dy};
}

void mozhegova::Rectangle::move(double dx, double dy)
{
  lowerLeft_ = {lowerLeft_.x + dx, lowerLeft_.y + dy};
  upperRight_ = {upperRight_.x + dx, upperRight_.y + dy};
}

void mozhegova::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale");
  }
  point_t center = getFrameRect().pos;
  double xLeft = center.x - (center.x - lowerLeft_.x) * k;
  double yLeft = center.y - (center.y - lowerLeft_.y) * k;
  lowerLeft_ = {xLeft, yLeft};
  double xRight = center.x + (upperRight_.x - center.x) * k;
  double yRight = center.y + (upperRight_.y - center.y) * k;
  upperRight_ = {xRight, yRight};
}
