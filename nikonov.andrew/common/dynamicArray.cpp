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
  char elem = ' ';
  size_t index = 0;
  std::noskipws(input);
  while ((input >> elem) && (elem != '\n'))
  {
    if (index == capacity - 1)
    {
      char* extendedline = reallocate(line, capacity);
      if (extendedline == nullptr)
      {
        free(line);
        return nullptr;
      }
      line = extendedline;
    }
    *(line + index) = elem;
    ++index;
  }
  if (*line == '\n')
  {
    free(line);
    return nullptr;
  }
  std::skipws(input);
  return line;
}
void nikonov::transferLine(char* oldLine, char* newLine)
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
char* nikonov::reallocate(char* line, size_t& capacity, int addSizeOptional)
{
  char* newline = nullptr;
  size_t tempCapacity = 0;
  if (addSizeOptional == -2)
  {
    size_t c = 2;
    tempCapacity = capacity * c;
    newline = reinterpret_cast< char* >(malloc(tempCapacity));
  }
  else
  {
    tempCapacity = capacity + addSizeOptional;
    newline = reinterpret_cast< char* >(malloc(tempCapacity));
  }
  if (newline == nullptr)
  {
    return nullptr;
  }
  for (size_t i = 0; i < tempCapacity; ++i)
  {
    *(newline + i) = '\0';
  }
  nikonov::transferLine(line, newline);
  free(line);
  capacity = tempCapacity;
  return newline;
}
