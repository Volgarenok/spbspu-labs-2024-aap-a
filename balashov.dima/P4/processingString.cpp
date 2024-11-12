#include "processingString.hpp"
#include <iostream>
#include <math.h>

char* balashov::removeSpaces(char* line)
{
  int numberSymbolOfNewLine = 0;
  for (int i = 0; line[i] != '\0'; ++i)
  {
    if (line[i] != ' ')
    {
      line[numberSymbolOfNewLine++] = line[i];
    }
    else
    {
      if ((line[i + 1] != ' ') && (numberSymbolOfNewLine != 0) && !(line[i + 1] == '\0'))
      {
        line[numberSymbolOfNewLine++] = line[i];
      }
    }
  }
  line[numberSymbolOfNewLine] = '\0';
  return line;
}

char* balashov::increaseSizeLine(char* lineStart, size_t& capacity)
{
  const double sizeIncreaseFactor = 1.4;
  size_t capacityBefore = capacity;
  capacity = std::ceil(capacityBefore * sizeIncreaseFactor);
  char* newLine = reinterpret_cast<char*>(malloc(sizeof(char) * capacity));
  if (newLine == nullptr)
  {
  throw;
  }
  for (size_t i = 0; i < capacityBefore; ++i)
  {
  newLine[i] = lineStart[i];
  }
  free(lineStart);
  return newLine;
}

char* balashov::enteringLine(size_t& capacity)
{
  char symbol = '\0';
  size_t sizeLine = 0;
  char* line = reinterpret_cast<char*>(malloc(sizeof(char) * capacity));
  if (line == nullptr)
  {
    throw;
  }
  std::noskipws(std::cin);
  while ((std::cin >> symbol) && (symbol != '\n'))
  {
    line[sizeLine++] = symbol;
    if (sizeLine == capacity)
    {
      try
      {
        line = increaseSizeLine(line, capacity);
       }
       catch (...)
       {
         throw;
       }
     }
   }
   line[sizeLine] = '\0';
   std::skipws(std::cin);
   return line;
}
