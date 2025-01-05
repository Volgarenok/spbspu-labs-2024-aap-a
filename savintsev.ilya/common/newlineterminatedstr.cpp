#include "newlineterminatedstr.h"
#include <cstddef>
#include <iostream>
#include "lrgcpy.hpp"

namespace savintsev
{
  constexpr size_t MEMORY_SIZE = 5;
}

char * savintsev::inputNewlineTerminatedStr(std::istream & in)
{
  size_t capacity = savintsev::MEMORY_SIZE;
  char * t = nullptr;
  try
  {
    t = new char[capacity];
  }
  catch (const std::bad_alloc & e)
  {
    return nullptr;
  }
  size_t i = 0;
  char buffer = 'a';
  while (!in.eof())
  {
    if (i == (capacity - 1))
    {
      t[i] = '\0';
      char * new_t = createAmpCopy(t, capacity, capacity + capacity);
      delete[] t;
      if (new_t == nullptr)
      {
        return nullptr;
      }
      t = new_t;
      capacity += capacity;
    }
    in >> std::noskipws >> buffer;
    t[i++] = buffer;
    if (buffer == '\n')
    {
      break;
    }
  }
  t[i - 1] = '\0';
  return t;
}
