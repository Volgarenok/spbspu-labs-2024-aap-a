#include "scale_functions.hpp"
#include "rectangle.hpp"
#include <iomanip>

void lanovenko::scaleShapes(Shape* const* shapeArray, const double* scaleParametrs, std::ostream& out, size_t shapesCapacity)
{
  if (shapesCapacity == 0)
  {
    throw std::invalid_argument("Nothing to scale!\n");
  }
  point_t toMoveCenter = { scaleParametrs[0], scaleParametrs[1] };
  double coefficient = scaleParametrs[2];
  outputScaleResults(shapeArray, shapesCapacity, out);
  toScale(shapeArray, toMoveCenter, coefficient, shapesCapacity);
  outputScaleResults(shapeArray, shapesCapacity, out);
}

void lanovenko::toScale(Shape* const* shape, point_t toMoveCenter, double k, size_t shapesCapacity)
{
  for (size_t i = 0; i < shapesCapacity; i++)
  {
    point_t initial = shape[i]->getFrameRect().pos;
    shape[i]->move(toMoveCenter);
    double deltaX = (shape[i]->getFrameRect().pos.x - initial.x) * k;
    double deltaY = (shape[i]->getFrameRect().pos.y - initial.y) * k;
    shape[i]->scale(k);
    shape[i]->move(-deltaX, -deltaY);
  }
}


void lanovenko::outputScaleResults(const Shape* const* shapeArray, size_t shapesCapacity, std::ostream& out)
{
  double totalArea = 0;
  for (size_t i = 0; i < shapesCapacity; i++)
  {
    totalArea += shapeArray[i]->getArea();
  }
  out << std::fixed << std::setprecision(1) << totalArea;
  for (size_t i = 0; i < shapesCapacity; i++)
  {
    rectangle_t temporaryRectangle = shapeArray[i]->getFrameRect();
    double leftLowerX = temporaryRectangle.pos.x - (temporaryRectangle.width / 2.0);
    double leftLowerY = temporaryRectangle.pos.y - (temporaryRectangle.height / 2.0);
    double rightUpperX = temporaryRectangle.pos.x + (temporaryRectangle.width / 2.0);
    double rightUpeerY = temporaryRectangle.pos.y + (temporaryRectangle.height / 2.0);
    out << std::fixed << std::setprecision(1) << ' ' << leftLowerX << ' ' << leftLowerY << ' ' << rightUpperX << ' ' << rightUpeerY;
  }
  out << '\n';
}
