#include "shape.hpp"
#include <stdexcept>
#include <cmath>
void alymova::scale(Shape** shapes, point_t s, double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("The scale ratio should be positive");
  }
  if (ratio == 1)
  {
    return;
  }
  for (size_t i = 0; shapes[i] != nullptr; i++)
  {
    shapes[i]->move(s);
    point_t shift_point(shapes[i]->getFrameRect().getShift());
    shapes[i]->scale(ratio);
    shift_point *= ratio;
    shapes[i]->move(-shift_point.x, -shift_point.y);
  }
}
double alymova::getVector(point_t p1, point_t p2)
{
  return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}
bool alymova::getRectanglurTriangle(point_t& pos, point_t& p2, point_t& p3)
{
  if (std::pow(getVector(p2, p3), 2) + std::pow(getVector(pos, p3), 2) == std::pow(getVector(pos, p2), 2))
  {
    return true;
  }
  else if (std::pow(getVector(p2, p3), 2) + std::pow(getVector(pos, p2), 2) == std::pow(getVector(pos, p3), 2))
  {
    point_t temp(p2);
    p2 = p3;
    p3 = temp;
    return true;
  }
  return false;
}
