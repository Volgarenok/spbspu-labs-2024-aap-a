#include "shape.hpp"
#include <stdexcept>
void kiselev::destroyShapePtr(Shape** shapes, size_t count)
{
  for (size_t i = 0; i < count; ++i)
  {
    delete shapes[i];
  }
}
void kiselev::Shape::scaleWithCheck(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Incorrect scaling coefficent");
  }
  this->scale(k);
}
