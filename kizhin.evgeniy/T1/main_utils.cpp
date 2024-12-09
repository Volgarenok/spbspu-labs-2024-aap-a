#include "main_utils.hpp"

void kizhin::resetPointers(char** str, double** params)
{
  delete[] *str;
  delete[] *params;
  *str = nullptr;
  *params = nullptr;
}

void kizhin::deleteShapes(Shape* const* shapes, size_t& size)
{
  size_t deleted = 0;
  for (kizhin::Shape* const* i = shapes; i != shapes + size; ++i, ++deleted) {
    delete *i;
  }
  size -= deleted;
}
