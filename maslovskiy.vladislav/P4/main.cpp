#include <iostream>
#include <cstddef>
#include <getLine.hpp>
#include "mergeStrs.hpp"

int main()
{
  size_t capacity = 10;
  char* firstLine = maslovskiy::getLine(std::cin, capacity);
  if (!firstLine)
  {
    std::cerr << "ERROR: Unable to read input string\n";
    return 1;
  }
  if (*firstLine == '\0')
  {
    std::cerr << "ERROR: Input string is empty\n";
    free(firstLine);
    return 2;
  }
  const char secondLine[] = "def_";
  size_t resultCapacity = capacity + sizeof(secondLine) - 1;
  char* resultLine = reinterpret_cast< char* >(malloc(resultCapacity));
  if (!resultLine)
  {
    free(firstLine);
    std::cerr << "ERROR: Memory allocation failed for the result string\n";
    return 1;
  }
  maslovskiy::mergeStrs(resultLine, firstLine, secondLine);
  std::cout << resultLine << '\n';
  free(resultLine);
  free(firstLine);
  return 0;
}
