#ifndef DESTROY_HPP
#define DESTROY_HPP
#include <cstddef>
#include "shape.hpp"

namespace duhanina
{
  template <typename T>
  void destroy(T** shapes, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      delete shapes[i];
    }
  }
}

#endif
