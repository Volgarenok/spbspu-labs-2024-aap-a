#include "dynamicArray.hpp"
#include <iostream>
#include <memory>
#include <cstddef>
char* nikonov::getLine(std::istream& input, size_t& capacity)
{
  char* line = reinterpret_cast< char* >(malloc(capacity));
  if (line == nullptr)
  {
    return nullptr;
  }
  for (size_t i = 0; i < capacity; ++i)
  {
    *(line + i) = '\0';
  }
  *(line + capacity - 1) = '\0';
  char elem = ' ';
  size_t index = 0;
  std::noskipws(input);
  while ((input >> elem) && (elem != '\n'))
  {
    if (index == capacity - 1)
    {
      char* extendedline = reallocate(line, capacity, 2);
      if (extendedline == nullptr)
      {
        free(line);
        std::skipws(input);
        return nullptr;
      }
      line = extendedline;
    }
    *(line + index) = elem;
    ++index;
  }
  if (!input)
  {
    free(line);
    std::skipws(input);
    return nullptr;
  }
  std::skipws(input);
  return line;
}
void nikonov::transferLine(const char* oldLine, char* newLine)
{
  if (oldLine && newLine)
  {
    while (*oldLine != '\0')
    {
      *newLine = *oldLine;
      ++oldLine;
      ++newLine;
    }
  }
}
char* nikonov::reallocate(char* line, size_t& capacity, int k, int addSizeOptional)
{
  char* newline = nullptr;
  size_t tempCapacity = 0;
  tempCapacity = capacity * k + addSizeOptional;
  newline = reinterpret_cast< char* >(malloc(tempCapacity));
  if (newline == nullptr)
  {
    return nullptr;
  }
  for (size_t i = 0; i < tempCapacity; ++i)
  {
    *(newline + i) = '\0';
  }
  transferLine(line, newline);
  free(line);
  capacity = tempCapacity;
  return newline;
}
