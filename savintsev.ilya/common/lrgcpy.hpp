#ifndef LRGCPY_HPP
#define LRGCPY_HPP
#include <cstddef>
#include <new>

namespace savintsev
{
  template < typename T >
  T * createAmpCopy(const T * old, size_t old_size, size_t new_size)
  {
    T * created = new T[new_size];
    try
    {
      for (size_t i = 0; i < old_size; ++i)
      {
        created[i] = old[i];
      }
    }
    catch (const std::bad_alloc & e)
    {
      delete created;
      return nullptr;
    }
    return created;
  }
}

#endif
