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
  *(line + capacity - 1) = 'e';
  nikonov::fillLine(line);
  char elem = ' ';
  char* lineBegin = line;
  std::noskipws(input);
  while ((input >> elem) && (elem != '\n'))
  {
    if (*line == 'e')
    {
      char* extendedline = reallocate(line, capacity);
      if (extendedline == nullptr)
      {
        free(lineBegin);
        return nullptr;
      }
      line = extendedline;
      lineBegin = extendedline;
    }
    *(line) = elem;
    ++line;
  }
  if (!input)
  {
    free(lineBegin);
    return nullptr;
  }
  std::skipws(input);
  return lineBegin;
}
void nikonov::fillLine(char* line, char what)
{
  while (*line != 'e')
  {
    *(line) = what;
    ++line;
  }
}
void nikonov::transferLine(char* oldLine, char* newLine)
{

  while (*oldLine != '\0')
  {
    *newLine = *oldLine;
    ++oldLine;
    ++newLine;
  }
}
char* nikonov::reallocate(char* line, size_t& capacity, int addSizeOptional)
{
  char* newline = nullptr;
  size_t tempCapacity = 0;
  if (addSizeOptional == -1)
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
  *(newline + tempCapacity - 1) = 'e';
  nikonov::fillLine(newline);
  nikonov::transferLine(line, newline);
  free(line);
  capacity = tempCapacity;
  return newline;
}
