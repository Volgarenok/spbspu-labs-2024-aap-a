#ifndef RESIZE_LINE_HPP
#define RESIZE_LINE_HPP
#include <iostream>

namespace zakirov
{
  char * get_to_symbol(std::istream & in, size_t step, char interrupt_symbol);
  void get_segment(std::istream & in, char * line, size_t start, size_t finish, char interrupt_el);
  template < typename T >
  T * extra_elements(const T * array, size_t size, size_t expansion)
  {
    T * new_array = static_cast< T * >(malloc((size + expansion) * sizeof(T)));
    if (new_array == nullptr)
    {
      return new_array;
    }

    for (size_t i = 0; i < size; ++i)
    {
      new_array[i] = array[i];
    }

    return new_array;
  }
}

#endif
