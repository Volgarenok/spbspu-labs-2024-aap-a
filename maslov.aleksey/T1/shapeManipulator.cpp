#include "shapeManipulator.hpp"
#include <iostream>

double maslov::getSumArea(const Shape * const * const shapes, const size_t count)
{
  double sum = 0.0;
  for (size_t i = 0; i < count; i++)
  {
    sum += shapes[i]->getArea();
  }
  return sum;
}
void maslov::scaleShapes(Shape ** shapes, const size_t count,
    const point_t scaleCoordinate, const double scaleFactor)
{
  for (size_t i = 0; i < count; i++)
  {
    point_t centerBefore = shapes[i]->getFrameRect().pos;
    shapes[i]->move(scaleCoordinate);
    point_t centerAfter = shapes[i]->getFrameRect().pos;
    shapes[i]->scale(scaleFactor);
    double newX = (centerAfter.x - centerBefore.x) * scaleFactor;
    double newY = (centerAfter.y - centerBefore.y) * scaleFactor;
    shapes[i]->move(-newX, -newY);
  }
}
void maslov::printCoordinates(const Shape * const * const shapes, const size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    rectangle_t rectangle = shapes[i]->getFrameRect();
    double heightHalf = rectangle.height / 2.0;
    double widthHalf = rectangle.width / 2.0;
    double centerX = rectangle.pos.x;
    double centerY = rectangle.pos.y;
    double lowerLeftCornerX = centerX - widthHalf;
    double lowerLeftCornerY = centerY - heightHalf;
    double upperRightCornerX = centerX + widthHalf;
    double upperRightCornerY = centerY + heightHalf;
    std::cout << lowerLeftCornerX << " " << lowerLeftCornerY << " ";
    std::cout << upperRightCornerX << " " << upperRightCornerY;
  }
}
void maslov::destroyShapes(Shape ** shapes, const size_t count)
{
  for (size_t i = 0; i < count; ++i)
  {
    delete shapes[i];
  }
}
