#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"

shabalin::Rectangle::Rectangle(point_t fp, point_t sp):
  rightUp(sp),
  leftDown(fp)
{
  if (leftDown.y > rightUp.y || leftDown.x > rightUp.x)
  {
    throw std::logic_error("Invalid arguments!");
  }
}

double shabalin::Rectangle::getArea() const
{
  double width = rightUp.x - leftDown.x;
  double height = rightUp.y - leftDown.y;
  return width * height;
}

shabalin::rectangle_t shabalin::Rectangle::getFrameRect() const
{
  double width = std::abs(rightUp.x - leftDown.x);
  double height = std::abs(rightUp.y - leftDown.y);
  point_t midpoint = {((rightUp.x + leftDown.x) / 2), ((rightUp.y + leftDown.y) / 2)};
  return {width, height, midpoint};
}

void shabalin::Rectangle::move(const point_t point)
{
  rectangle_t data = getFrameRect();
  double delX = point.x - data.pos.x;
  double delY = point.y - data.pos.y;
  move(delX, delY);
}

void shabalin::Rectangle::move(const double delX, const double delY)
{
  point_t * pointsArray[2] = {&leftDown, &rightUp};
  for (size_t i = 0; i < 2; i++)
  {
    pointsArray[i]->x += delX;
    pointsArray[i]->y += delY;
  }
}

void shabalin::Rectangle::scaleShape(const double k)
{
  rectangle_t data = getFrameRect();
  double widthWithScale = data.width * k;
  double heightWithScale = data.height * k;
  double widthHalf = widthWithScale / 2.0;
  double heightHalf = heightWithScale / 2.0;
  leftDown.x = data.pos.x - widthHalf;
  leftDown.y = data.pos.y - heightHalf;
  rightUp.x = data.pos.x + widthHalf;
  rightUp.y = data.pos.y + heightHalf;
}
