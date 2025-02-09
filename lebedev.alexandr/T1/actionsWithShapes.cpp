#include "actionsWithShapes.hpp"
#include <iostream>

double lebedev::getSumArea(const lebedev::Shape** shps, size_t count)
{
  if (shps == nullptr)
  {
    return 0;
  }
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

void lebedev::printFrameCoordinates(const lebedev::Shape** shps, size_t count, std::ostream& output)
{
  for (size_t i = 0; i < count; ++i)
  {
    lebedev::rectangle_t rect = shps[i]->getFrameRect();
    double leftDownX = rect.pos.x - rect.width / 2;
    double leftDownY = rect.pos.y - rect.height / 2;
    double rightUpX = rect.pos.x + rect.width / 2;
    double rightUpY = rect.pos.y + rect.height / 2;
    output << ' ' << leftDownX << ' ' << leftDownY << ' ' << rightUpX << ' ' << rightUpY;
  }
  output << '\n';
}
