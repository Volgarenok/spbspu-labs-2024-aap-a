#include "lineinput.hpp"
#include <iostream>
#include <memory>
#include <cstddef>
char* getLine(size_t& capacity)
{
  char* line = reinterpret_cast<char*>(malloc(capacity));
  if (line == nullptr)
  {
    return nullptr;
  }
  char elem = ' ';
  size_t cnt = 0;
  while (std::cin >> std::noskipws >> elem && elem != '\n')
  {
    if (cnt == capacity - 1)
    {
      line[cnt + 1] = '\0';
      line = reallocate(line, capacity);
      if (line == nullptr)
      {
        return nullptr;
      }
    }
    line[cnt] = elem;
    ++cnt;
  }
  if (!std::cin)
  {
    free(line);
    return nullptr;
  }
  std::skipws(std::cin);
  line[cnt] = '\0';
  return line;
}
char* reallocate(char* line, size_t& capacity)
{
  capacity = capacity * 2;
  char* newline = reinterpret_cast<char*>(malloc(capacity));
  if (newline == nullptr)
  {
    free(line);
    return nullptr;
  }
  size_t newcnt = 0;
  while (line[newcnt] != '\0')
  {
    newline[newcnt] = line[newcnt];
    ++newcnt;
  }
  newline[newcnt] = '\0';
  free(line);
  return newline;
}
char* reallocate(char* line, size_t& capacity, size_t addSize)
{
  capacity = capacity + addSize;
  char* newline = reinterpret_cast<char*>(malloc(capacity));
  if (newline == nullptr)
  {
    free(line);
    return nullptr;
  }
  size_t newcnt = 0;
  while (line[newcnt] != '\0')
  {
    newline[newcnt] = line[newcnt];
    ++newcnt;
  }
  newline[newcnt] = '\0';
  free(line);
  return newline;
}
