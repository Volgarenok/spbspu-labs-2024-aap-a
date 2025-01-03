#ifndef LRGCPY_HPP
#define LRGCPY_HPP
#include <cstddef>
#include <stdexcept>

namespace savintsev
{
  template < typename T >
  T * createAmpCopy(const T * old, size_t old_size, size_t new_size)
  {
    T * created = nullptr;
    try
    {
      created = new T[new_size];
      for (size_t i = 0; i < old_size; ++i)
      {
        created[i] = old[i];
      }
    }
    catch (const std::exception & e)
    {
      delete created;
      return nullptr;
    }
    return created;
  }
}
#endif
