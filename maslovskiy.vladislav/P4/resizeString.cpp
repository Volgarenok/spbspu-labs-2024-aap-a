#include "resizeString.hpp"
#include <cstdlib>
#include <new>
#include <iostream>

char* maslovskiy::resizeString(const char *str, size_t strSize, size_t iterSize)
{
  char *resized = static_cast<char*>(malloc(sizeof(char) * (strSize + iterSize + 1)));
  if (resized == nullptr)
  {
    std::cerr << "Error: memory not allocate for string or incorrect parameters\n";
    return nullptr;
  }
  for (size_t i = 0; i < strSize; ++i)
  {
    resized[i] = str[i];
  }
  resized[strSize + iterSize] = '\0';
  return resized;
}
