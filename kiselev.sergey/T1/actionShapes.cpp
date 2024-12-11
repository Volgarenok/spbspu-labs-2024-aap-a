#include "actionShapes.hpp"
#include <iostream>
double kiselev::getSumArea(kiselev::Shape** shapes, size_t countShape)
{
  double sum = 0;
  for (size_t i = 0; i < countShape; ++i)
  {
    sum += shapes[i]->getArea();
  }
  return sum;
}
void kiselev::scaleForShapes(kiselev::Shape** shapes, size_t countShape, kiselev::point_t scale, double ratio)
{
  for (size_t i = 0; i < countShape; ++i)
  {
    kiselev::point_t beforeScale = shapes[i]->getFrameRect().pos;
    shapes[i]->move(scale);
    kiselev::point_t afterScale = shapes[i]->getFrameRect().pos;
    kiselev::point_t vector = { (afterScale.x - beforeScale.x) * ratio, (afterScale.y - beforeScale.y) * ratio };
    shapes[i]->scale(ratio);
    shapes[i]->move(-vector.x, -vector.y);
  }
}
void kiselev::printCoordinatesRect(kiselev::Shape** shapes, size_t countShape)
{
  for (size_t i = 0; i < countShape; ++i)
  {
    kiselev::rectangle_t rect = shapes[i]->getFrameRect();
    double leftDownX = rect.pos.x - rect.width / 2;
    double leftDownY = rect.pos.y - rect.height / 2;
    double rightUpX = rect.pos.x + rect.width / 2;
    double rightUpY = rect.pos.y + rect.height / 2;
    std::cout << " " << leftDownX << " " << leftDownY << " " << rightUpX << " " << rightUpY;
  }
  std::cout << "\n";
}
