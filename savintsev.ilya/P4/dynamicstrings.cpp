#include "dynamicstrings.h"
#include <cstddef>
#include <iostream>

namespace savintsev
{
  constexpr size_t MEMORY_SIZE = 8;
}

char * savintsev::inputEndlessStr(std::istream & in)
{
  size_t capacity = savintsev::MEMORY_SIZE;
  char * t = nullptr;
  try
  {
    t = allocMemoryStr(capacity);
  }
  catch (const std::bad_alloc & e)
  {
    return nullptr;
  }
  size_t i = 0;
  while (!in.eof())
  {
    if (i == (capacity - 1))
    {
      t[i] = '\0';
      capacity += capacity;
      try
      {
        t = savintsev::increaseStrSize(t, capacity);
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

char * savintsev::increaseStrSize(char * old, size_t new_size)
{
  char * created = new char[new_size];
  for (size_t i = 0; old[i] != '\0'; ++i)
  {
    created[i] = old[i];
  }
  delete[] old;
  return created;
}

int savintsev::getNumIdenticalInRow(char * c)
{
  if (c == nullptr)
  {
    return -1;
  }
  if (c[0] == '\0')
  {
    return -1;
  }
  int k = 0;
  for (size_t i = 0; c[i] != '\0'; ++i)
  {
    if (c[i] == c[i + 1])
    {
      ++k;
    }
  }
  return k;
}

char * savintsev::allocMemoryStr(size_t cap)
{
  char * t = new char[cap];
  return t;
}