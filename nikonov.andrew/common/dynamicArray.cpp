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
  char elem = ' ';
  size_t index = 0;
  std::noskipws(input);
  while ((input >> elem) && (elem != '\n'))
  {
    if (index == capacity - 1)
    {
      *(line + index) = '\0';
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
  *(line + index) = '\0';
  if (!input.eof() && !input)
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
    *newLine = '\0';
  }
}
char* nikonov::reallocate(char* line, size_t& capacity, size_t k, size_t addSizeOptional)
{
  size_t tempCapacity = capacity * k + addSizeOptional;
  char* newline = reinterpret_cast< char* >(malloc(tempCapacity));
  if (newline == nullptr)
  {
    return nullptr;
  }
  transferLine(line, newline);
  free(line);
  capacity = tempCapacity;
  return newline;
}
