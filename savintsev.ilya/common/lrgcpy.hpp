#ifndef LRGCPY_HPP
#define LRGCPY_HPP
#include <cstddef>

namespace savintsev
{
  template <typename T>
  T * createAmpCpyAny(const T * old, size_t old_size, size_t new_size)
  {
    T * created = new T[new_size];
    for (size_t i = 0; i < old_size; ++i)
    {
      created[i] = old[i];
    }
    return created;
  }
}

#endif
