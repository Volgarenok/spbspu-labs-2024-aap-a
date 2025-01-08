#include "rectangle.hpp"
#include <stdexcept>

mozhegova::Rectangle::Rectangle(point_t lowLef, point_t uppRig):
  lowerLeft(lowLef),
  upperRight(uppRig)
{
  if (lowLef.x >= uppRig.x || lowLef.y >= uppRig.y)
  {
    throw std::invalid_argument("Incorrect coordinates");
  }
}

double mozhegova::Rectangle::getArea() const
{
  double width = upperRight.x - lowerLeft.x;
  double height = upperRight.y - lowerLeft.y;
  return width * height;
}

mozhegova::rectangle_t mozhegova::Rectangle::getFrameRect() const
{
  double width = upperRight.x - lowerLeft.x;
  double height = upperRight.y - lowerLeft.y;
  double x_ = lowerLeft.x + (width / 2.0);
  double y_ = lowerLeft.y + (height / 2.0);
  return {width, height, {x_, y_}};
}

void mozhegova::Rectangle::move(point_t p)
{
  point_t center = getFrameRect().pos;
  double dx = p.x - center.x;
  double dy = p.y - center.y;
  lowerLeft = {lowerLeft.x + dx, lowerLeft.y + dy};
  upperRight = {upperRight.x + dx, upperRight.y + dy};
}

void mozhegova::Rectangle::move(double dx, double dy)
{
  lowerLeft = {lowerLeft.x + dx, lowerLeft.y + dy};
  upperRight = {upperRight.x + dx, upperRight.y + dy};
}

void mozhegova::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale");
  }
  point_t center = getFrameRect().pos;
  double xLeft = center.x - (center.x - lowerLeft.x) * k;
  double yLeft = center.y - (center.y - lowerLeft.y) * k;
  lowerLeft = {xLeft, yLeft};
  double xRight = center.x + (upperRight.x - center.x) * k;
  double yRight = center.y + (upperRight.y - center.y) * k;
  upperRight = {xRight, yRight};
}
