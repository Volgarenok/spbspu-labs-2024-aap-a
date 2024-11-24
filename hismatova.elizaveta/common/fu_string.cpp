#include "fu_string.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

int hismatova::getLine(char** str)
{
  size_t n = 256;
  *str = reinterpret_cast<char*>(malloc(sizeof(char) * n));
  if (*str == nullptr) {
    std::cerr << "out of memory\n";
    return 1;
  }
  size_t length = 0;
  int c = 0;
  while (true) {
    c = std::cin.get();
    if (c == '\n' || c == EOF)
    {
      break;
    }
    if (length + 1 >= n)
    {
      n *= 2;
      *str = reinterpret_cast<char*>(realloc(*str, n));
      if (*str == nullptr)
      {
        std::cerr << "out of memory\n";
        return 1;
      }
    }
    (*str)[length++] = static_cast<char>(c);
  }
  (*str)[length] = '\0';
  return 0;
}
