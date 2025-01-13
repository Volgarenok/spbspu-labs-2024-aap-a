#include "actionsWithShapes.hpp"
#include <iostream>

double lebedev::getSumArea(lebedev::Shape** shps, size_t count)
{
  double result = 0;
  for (size_t i = 0; i < count; ++i)
  {
    result += shps[i]->getArea();
  }
  return result;
}

void lebedev::scaleForShapes(lebedev::Shape** shps, size_t count, lebedev::point_t scalePoint, double k)
{
  for (size_t i = 0; i < count; ++i)
  {
    lebedev::point_t beforeScale = shps[i]->getFrameRect().pos;
    shps[i]->move(scalePoint);
    lebedev::point_t afterScale = shps[i]->getFrameRect().pos;
    lebedev::point_t vector = { (afterScale.x - beforeScale.x) * k, (afterScale.y - beforeScale.y) * k };
    shps[i]->scale(k);
    shps[i]->move(-vector.x, -vector.y);
  }
}

void lebedev::printFrameCoordinates(lebedev::Shape** shps, size_t count)
{
  for (size_t i = 0; i < count; ++i)
  {
    lebedev::rectangle_t rect = shps[i]->getFrameRect();
    double leftDownX = rect.pos.x - rect.width / 2;
    double leftDownY = rect.pos.y - rect.height / 2;
    double rightUpX = rect.pos.x + rect.width / 2;
    double rightUpY = rect.pos.y + rect.height / 2;
    std::cout << ' ' << leftDownX << ' ' << leftDownY << ' ' << rightUpX << ' ' << rightUpY;
  }
  std::cout << '\n';
}
