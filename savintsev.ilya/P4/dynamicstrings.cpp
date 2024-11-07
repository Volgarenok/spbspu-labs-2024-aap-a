#include "dynamicstrings.h"
#include <cstddef>
#include <iostream>

namespace savintsev
{
  constexpr size_t MEMSIZE = 5;
}

char * savintsev::inputEndlessString(std::istream & in)
{
  size_t memory = savintsev::MEMSIZE;
  char * t = new char[memory];
  size_t i = 0;
  while (true)
  {
    if (i == (memory - 1))
    {
      t[i] = '\0';
      memory += memory;
      try
      {
        t = savintsev::increaseStringSize(t, memory);
      }
      catch (const std::bad_alloc & e)
      {
        return t;
      }
    }
    in >> std::noskipws >> t[i];
    if (in.eof())
    {
      break;
    }
    ++i;
  }
  t[i + 1] = '\0';
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
