#include "processingString.hpp"
#include <cmath>

char* balashov::removeSpaces(char * line)
{
  char* lineWithoutSpaces = line;
  char* pointerToChange = line;
  bool spaceLastSymbol = false;
  bool isFirstSymbol = true;
  while (*line != '\0')
  {
    if (*line != ' ')
    {
      *pointerToChange++ = *line;
      spaceLastSymbol = false;
      isFirstSymbol = false;
    }
    else if (!spaceLastSymbol && !isFirstSymbol)
    {
      *pointerToChange++ = ' ';
      spaceLastSymbol = true;
    }
    line++;
  }
  if (spaceLastSymbol && !isFirstSymbol)
  {
    pointerToChange--;
  }
  *pointerToChange = '\0';
  return lineWithoutSpaces;
}

char* balashov::increaseSizeLine(const char* lineStart, size_t& capacity)
{
  const double sizeIncreaseFactor = 1.4;
  size_t capacityBefore = capacity;
  size_t temporaryСapacity = std::ceil(capacityBefore * sizeIncreaseFactor);
  char* newLine = reinterpret_cast< char* >(malloc(temporaryСapacity));
  if (newLine == nullptr)
  {
    return nullptr;
  }
  capacity = temporaryСapacity;
  for (size_t i = 0; i < capacityBefore; ++i)
  {
    newLine[i] = lineStart[i];
  }
  return newLine;
}

char* balashov::enteringLine(std::istream & in, size_t & capacity)
{
  char symbol = '\0';
  size_t sizeLine = 0;
  char* line = reinterpret_cast< char* >(malloc(capacity));
  if (line == nullptr)
  {
    return nullptr;
  }
  std::noskipws(in);
  while ((in >> symbol) && (symbol != '\n'))
  {
    line[sizeLine++] = symbol;
    if (sizeLine == capacity)
    {
      char * newLine = increaseSizeLine(line, capacity);
      free(line);
      if (newLine == nullptr)
      {
        std::skipws(in);
        return nullptr;
      }
      line = newLine;
    }
  }
  line[sizeLine] = '\0';
  std::skipws(in);
  return line;
}
