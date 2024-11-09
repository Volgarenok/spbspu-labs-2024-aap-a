#include <lineinput.hpp>
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
  std::noskipws(std::cin);
  while (std::cin >> elem && elem != '\n' && elem != ' ')
  {
    if (cnt == capacity)
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
  free(line);
  return newline;
}
