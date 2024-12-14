#include "shapeManipulator.hpp"
#include <iostream>

double maslov::getSumArea(maslov::Shape** shapes, size_t count)
{
  double sum = 0;
  for (size_t i = 0; i < count; ++i)
  {
    sum += shapes[i]->getArea();
  }
  return sum;
}
void maslov::scaleShapes(maslov::Shape** shapes, size_t count, maslov::point_t scaleCoor, double scaleFactor)
{
  for (size_t i = 0; i < count; ++i)
  {
    maslov::point_t before = shapes[i]->getFrameRect().pos;
    shapes[i]->move(scaleCoor);
    maslov::point_t after = shapes[i]->getFrameRect().pos;
    maslov::point_t vector = { (after.x - before.x) * scaleFactor, (after.y - before.y) * scaleFactor };
    shapes[i]->scale(scaleFactor);
    shapes[i]->move(-vector.x, -vector.y);
  }
}
void maslov::printCoor(Shape** shapes, size_t count)
{
  for (size_t i = 0; i < count; ++i)
  {
    maslov::rectangle_t rect = shapes[i]->getFrameRect();
    double leftDownX = rect.pos.x - rect.width / 2;
    double leftDownY = rect.pos.y - rect.height / 2;
    double rightUpX = rect.pos.x + rect.width / 2;
    double rightUpY = rect.pos.y + rect.height / 2;
    std::cout << " " << leftDownX << " " << leftDownY << " " << rightUpX << " " << rightUpY;
  }
}