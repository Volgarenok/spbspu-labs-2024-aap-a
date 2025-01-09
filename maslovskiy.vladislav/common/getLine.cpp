#include "getLine.hpp"
#include <iostream>
#include <cstdlib>

char* maslovskiy::getLine(std::istream& input, size_t& capacity)
{
  char* line = reinterpret_cast< char* >(malloc(capacity));
  if (!line)
  {
    return nullptr;
  }
  char ch = ' ';
  size_t index = 0;
  input >> std::noskipws;
  while (input >> ch && ch != '\n')
  {
    if (index == capacity - 1)
    {
      char* extendedLine = reallocate(line, capacity, 2);
      if (!extendedLine)
      {
        free(line);
        return nullptr;
      }
      line = extendedLine;
    }
    line[index++] = ch;
  }
  line[index] = '\0';
  if (!input.eof() && !input)
  {
    free(line);
    return nullptr;
  }
  return line;
}

char* maslovskiy::reallocate(char* line, size_t& capacity, size_t factor, size_t addSizeOptional)
{
  size_t newCapacity = capacity * factor + addSizeOptional;
  char* newLine = reinterpret_cast< char* >(malloc(newCapacity));
  if (!newLine)
  {
    return nullptr;
  }
  for (size_t i = 0; i < capacity; ++i)
  {
    newLine[i] = line[i];
  }
  free(line);
  capacity = newCapacity;
  return newLine;
}
