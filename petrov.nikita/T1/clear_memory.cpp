#include "clear_memory.hpp"
#include "composite-shape.hpp"
#include "shape.hpp"
void petrov::clearMemory(petrov::CompositeShape * ptr_composite_shape)
{
  size_t size_of_composite_shape = ptr_composite_shape->size();
  for (size_t i = 0; i < size_of_composite_shape; i++)
  {
    ptr_composite_shape->pop_back();
  }
}
