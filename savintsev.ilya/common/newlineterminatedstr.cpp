#include "newlineterminatedstr.h"
#include <cstddef>
#include <iostream>

namespace savintsev
{
<<<<<<< HEAD
  constexpr size_t MEMORY_SIZE = 40;
=======
  constexpr size_t MEMORY_SIZE = 8;
>>>>>>> parent of f7ab4f9b (Revert "Merge branch 'dribas.sergey/P6' into dribas.sergey/P4")
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
<<<<<<< HEAD
  while (!in.eof())
=======
  while (in.good())
>>>>>>> parent of f7ab4f9b (Revert "Merge branch 'dribas.sergey/P6' into dribas.sergey/P4")
  {
    if (i == (capacity - 1))
    {
      t[i] = '\0';
      capacity += capacity;
      try
      {
        char * new_t = savintsev::createEnlargedCopiedStr(t, capacity);
        delete[] t;
        t = new_t;
      }
      catch (const std::bad_alloc & e)
      {
        delete[] t;
        return nullptr;
      }
    }
    in >> std::noskipws >> buffer;
    t[i++] = buffer;
    if (buffer == '\n')
    {
      break;
    }
  }
<<<<<<< HEAD
=======
  if (!in.good())
  {
    delete[] t;
    return nullptr;
  }
>>>>>>> parent of f7ab4f9b (Revert "Merge branch 'dribas.sergey/P6' into dribas.sergey/P4")
  t[i - 1] = '\0';
  return t;
}

char * savintsev::createEnlargedCopiedStr(const char * old, size_t new_size)
{
  char * created = new char[new_size];
  for (size_t i = 0; old[i] != '\0'; ++i)
  {
    created[i] = old[i];
  }
  return created;
}
