#include "lineinput.hpp"
#include <iostream>
#include <memory>
#include <cstddef>
char* nikonov::getLine(std::istream& input, size_t& capacity)
{
  char* line = reinterpret_cast<char*>(malloc(capacity));
  if (line == nullptr)
  {
    return nullptr;
  }
  for (size_t i = 0; i < capacity; ++i)
  {
    *(line + i) = '\0';
  }
  char elem = ' ';
  size_t cnt = 0;
  while (input >> std::noskipws >> elem && elem != '\n')
  {
    if (cnt == capacity - 1)
    {
      line = reallocate(line, capacity);
      if (line == nullptr)
      {
        return nullptr;
      }
    }
    *(line + cnt) = elem;
    ++cnt;
  }
  if (!input)
  {
    free(line);
    return nullptr;
  }
  std::skipws(input);
  return line;
}
char* nikonov::reallocate(char* line, size_t& capacity, int addSizeOptional)
{
  char* newline = nullptr;
  size_t tempCapacity = 0;
  if (addSizeOptional == -1)
  {
    size_t c = 2;
    tempCapacity = capacity * c;
    newline = reinterpret_cast<char*>(malloc(tempCapacity));
  }
  else
  {
    tempCapacity = capacity + addSizeOptional;
    newline = reinterpret_cast<char*>(malloc(tempCapacity));
  }
  if (newline == nullptr)
  {
    return nullptr;
  }
  size_t newcnt = 0;
  while (*(line + newcnt) != '\0')
  {
    *(newline + newcnt) = *(line + newcnt);
    ++newcnt;
  }
  
  for (size_t i = newcnt; i < tempCapacity; ++i)
  {
    *(newline + i) = '\0';
  }
  free(line);
  capacity = tempCapacity;
  return newline;
}
