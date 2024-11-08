#include "dynamicstrings.h"
#include <cstddef>
#include <iostream>

namespace savintsev
{
  constexpr size_t MEMORY_SIZE = 5;
}

char * savintsev::inputEndlessString(std::istream & in)
{
  size_t capacity = savintsev::MEMORY_SIZE;
  char * t = new char[capacity];
  size_t i = 0;
  while (!in.eof())
  {
    if (i == (capacity - 1))
    {
      t[i] = '\0';
      capacity += capacity;
      try
      {
        t = savintsev::increaseStringSize(t, capacity);
      }
      catch (const std::bad_alloc & e)
      {
        delete[] t;
        return nullptr;
      }
    }
    in >> std::noskipws >> t[i++];
  }
  t[i - 1] = '\0';
  return t;
}

char * savintsev::increaseStringSize(char * old, size_t new_size)
{
  char * created = new char[new_size];
  for (size_t i = 0; old[i] != '\0'; ++i)
  {
    created[i] = old[i];
  }
  delete[] old;
  return created;
}

size_t savintsev::getNumIdenticalInRow(char * c)
{
  if (c == nullptr)
  {
    return 0;
  }
  size_t k = 0;
  for (size_t i = 0; c[i] != '\0'; ++i)
  {
    if (c[i] == c[i + 1])
    {
      ++k;
    }
  }
  return k;
}
