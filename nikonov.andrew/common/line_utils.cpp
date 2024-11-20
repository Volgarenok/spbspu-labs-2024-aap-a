#include "line_utils.hpp"
#include <iostream>
#include <memory>
#include <cstddef>
char* nikonov::getLine(size_t& capacity)
{
  char* line = reinterpret_cast<char*>(malloc(capacity));
  if (line == nullptr)
  {
    return nullptr;
  }
  for (size_t i = 0; i < capacity; ++i)
  {
    line[i] = '\0';
  }
  char elem = ' ';
  size_t cnt = 0;
  while (std::cin >> std::noskipws >> elem && elem != '\n')
  {
    if (cnt == capacity - 1)
    {
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
  return line;
}
char* nikonov::reallocate(char* line, size_t& capacity)
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
  for (size_t i = newcnt; i < capacity; ++i)
  {
    newline[i] = '\0';
  }
  free(line);
  return newline;
}
char* nikonov::reallocate(char* line, size_t& capacity, size_t addSize)
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
  for (size_t i = newcnt; i < capacity; ++i)
  {
    newline[i] = '\0';
  }
  free(line);
  return newline;
}
void nikonov::printLine(const char* line)
{
  size_t iter = 0;
  while (line[iter] != '\0')
  {
    std::cout << line[iter];
    ++iter;
  }
  std::cout << "\n";
}
