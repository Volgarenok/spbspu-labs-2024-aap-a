#include "clear_memory.hpp"
#include "shape.hpp"
void petrov::clearMemory(Shape ** shapes_massive, size_t created)
{
  for (size_t i = 0; i < created; i++)
  {
    delete shapes_massive[i];
  }
}
