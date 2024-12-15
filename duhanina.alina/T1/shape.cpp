#include "shape.hpp"
#include <cstddef>

void duhanina::destroy(Shape** shapes, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    delete shapes[i];
  }
}
