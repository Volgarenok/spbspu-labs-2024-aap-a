#include "shapeManipulator.hpp"

double maslov::getSumArea(const CompositeShape & compositeShape)
{
  return compositeShape.getArea();
}
void maslov::scaleShapes(CompositeShape & compositeShape, point_t coordinate, double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Incorrect scale factor");
  }
  for (size_t i = 0; i < compositeShape.size(); i++)
  {
    point_t centerBefore = compositeShape[i]->getFrameRect().pos;
    compositeShape[i]->move(coordinate);
    point_t centerAfter = compositeShape[i]->getFrameRect().pos;
    compositeShape[i]->scaleWithoutCheck(factor);
    double newX = (centerAfter.x - centerBefore.x) * factor;
    double newY = (centerAfter.y - centerBefore.y) * factor;
    compositeShape[i]->move(-newX, -newY);
  }
}
void maslov::printData(std::ostream & out, const CompositeShape & compositeShape)
{
  out << getSumArea(compositeShape);
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
    out << " " << lowerLeftCornerX << " " << lowerLeftCornerY << " ";
    out << upperRightCornerX << " " << upperRightCornerY;
  }

}
void maslov::destroyShapes(CompositeShape & compositeShape)
{
  while (compositeShape.size() > 0)
  {
    compositeShape.pop_back();
  }
}
