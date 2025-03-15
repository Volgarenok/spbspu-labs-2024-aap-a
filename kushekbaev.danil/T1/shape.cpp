#include "shape.hpp"

void kushekbaev::Shape::scaleEverything(point_t scalePoint, double scaleCoeff)
{
  point_t beforeScale = getFrameRect().pos;
  move(scalePoint);
  point_t afterScale = getFrameRect().pos;
  point_t vector = { (afterScale.x - beforeScale.x) * scaleCoeff, (afterScale.y - beforeScale.y) * scaleCoeff };
  scale(scaleCoeff);
  move(-vector.x, -vector.y);
}
