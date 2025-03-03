#include "delete_shape.hpp"

void lanovenko::deleteShape(Shape** shapeArray, size_t res)
{
  for (size_t i = 0; i < res; i++)
  {
    delete shapeArray[i];
  }
}
