#include "shapeManipulator.hpp"

double maslov::getSumArea(const CompositeShape & compositeShape)
{
  return compositeShape.getArea();
}
void maslov::scaleShapes(CompositeShape & compositeShape,
    const point_t scaleCoordinate, const double scaleFactor)
{
  for (size_t i = 0; i < compositeShape.size(); i++)
  {
    point_t centerBefore = compositeShape[i]->getFrameRect().pos;
    compositeShape[i]->move(scaleCoordinate);
    point_t centerAfter = compositeShape[i]->getFrameRect().pos;
    compositeShape[i]->scale(scaleFactor);
    double newX = (centerAfter.x - centerBefore.x) * scaleFactor;
    double newY = (centerAfter.y - centerBefore.y) * scaleFactor;
    compositeShape[i]->move(-newX, -newY);
  }
}
void maslov::printCoordinates(std::ostream & out,
  const CompositeShape & compositeShape)
{
  for (size_t i = 0; i < compositeShape.size(); i++)
  {
    rectangle_t rectangle = compositeShape[i]->getFrameRect();
    double heightHalf = rectangle.height / 2.0;
    double widthHalf = rectangle.width / 2.0;
    double centerX = rectangle.pos.x;
    double centerY = rectangle.pos.y;
    double lowerLeftCornerX = centerX - widthHalf;
    double lowerLeftCornerY = centerY - heightHalf;
    double upperRightCornerX = centerX + widthHalf;
    double upperRightCornerY = centerY + heightHalf;
    out << lowerLeftCornerX << " " << lowerLeftCornerY << " ";
    out << upperRightCornerX << " " << upperRightCornerY;
    if (i < compositeShape.size() - 1)
    {
      out << " ";
    }
  }
}
void maslov::destroyShapes(CompositeShape & compositeShape)
{
  while (compositeShape.size() > 0)
  {
    compositeShape.pop_back();
  }
}
