#include "delete_shape.hpp"

void lanovenko::deleteShape(Shape** shapeArray, std::size_t res)
{
  for (size_t i = 0; i < res; i++)
  {
    delete shapeArray[i];
  }
}
