#include "rectangle.hpp"
#include <stdexcept>
#include <memory>
#include "base-types.hpp"
#include "shapeUtils.hpp"

kushekbaev::Rectangle::Rectangle(point_t lowerLeft, point_t upperRight):
  lowerLeft_(lowerLeft),
  upperRight_(upperRight)
{
  if (lowerLeft.x >= upperRight.x || lowerLeft.y >= upperRight.x)
  {
    throw std::invalid_argument("Incorrect rectangle");
  }
}

double kushekbaev::Rectangle::getArea() const
{
  return (upperRight_.x - lowerLeft_.x) * (upperRight_.y - lowerLeft_.y);
}

kushekbaev::rectangle_t kushekbaev::Rectangle::getFrameRect() const
{
  double middleForX = lowerLeft_.x + (upperRight_.x - lowerLeft_.x) / 2;
  double middleForY = lowerLeft_.y + (upperRight_.y - lowerLeft_.y) / 2;
  return { upperRight_.x - lowerLeft_.x, upperRight_.y - lowerLeft_.y, { middleForX, middleForY } };
}

void kushekbaev::Rectangle::move(point_t scalePoint)
{
  point_t mid = getFrameRect().pos;
  double dx = scalePoint.x - mid.x;
  double dy = scalePoint.y - mid.y;

  move(dx, dy);
}

void kushekbaev::Rectangle::move(double dx, double dy)
{
  size_t size = 2;
  point_t* points[] = { &lowerLeft_, &upperRight_ };
  movePoints(points, size, dx, dy);
}

kushekbaev::Shape* kushekbaev::Rectangle::clone() const
{
  return new Rectangle(*this);
}

void kushekbaev::Rectangle::doUnsafeScale(double scaleCoeff)
{
  point_t mid = Rectangle::getFrameRect().pos;
  size_t size = 2;
  point_t* points[] = { std::addressof(lowerLeft_), std::addressof(upperRight_) };
  scalePoints(points, size, scaleCoeff, mid);
}
