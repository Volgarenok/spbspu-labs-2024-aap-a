#include "actionsWithShapes.hpp"

double lebedev::getSumArea(Shape** shps, size_t count)
{
  double result = 0;
  for (size_t i = 0; i < count; ++i)
  {
    result += shps[i]->getArea();
  }
  return result;
}

void lebedev::scaleForShapes(Shape** shps, size_t count, point_t scalePoint, double k)
{
  for (size_t i = 0; i < count; ++i)
  {
    point_t beforeScale = shps[i]->getFrameRect().pos;
    shps[i]->move(scalePoint);
    point_t afterScale = shps[i]->getFrameRect().pos;
    point_t vector = { (afterScale.x - beforeScale.x) * k, (afterScale.y - beforeScale.y) * k };
    shps[i]->scale(k);
    shps[i]->move(-vector.x, -vector.y);
  }
}

void lebedev::printFrameCoordinates(const Shape* const* shps, size_t count, std::ostream& output)
{
  for (size_t i = 0; i < count; ++i)
  {
    rectangle_t rect = shps[i]->getFrameRect();
    double leftDownX = rect.pos.x - rect.width / 2;
    double leftDownY = rect.pos.y - rect.height / 2;
    double rightUpX = rect.pos.x + rect.width / 2;
    double rightUpY = rect.pos.y + rect.height / 2;
    output << ' ' << leftDownX << ' ' << leftDownY << ' ' << rightUpX << ' ' << rightUpY;
  }
  output << '\n';
}

void lebedev::deleteShapePtr(Shape** shps, size_t count)
{
  for (size_t i = 0; i < count; ++i)
  {
    delete shps[i];
  }
}
