#include "enterStr.hpp"
#include <iostream>
#include <cstddef>

char* swapStr(char* oldstr, char* newstr) {
  char* oldptr = oldstr;
  char* newptr = newstr;
  while(*oldptr != '\0') {
    *newptr  = *oldptr;
    oldptr++;
    newptr++;
  }
  *newptr = '\0';
  return newstr;
}

char* dribas::enterStr(std::istream & input)
{
  size_t size = 1;
  char lastStrSymbol = '\n';
  char lastSymbol = '\0';
  char enter = 0;
  char* str = static_cast< char* >(malloc(size * sizeof(char)));

  if (!str) {
    return str;
  }
  str[0] = lastSymbol;
  std::noskipws(input);
  input >> enter;
  while (enter != lastStrSymbol) {
    if (!input) {
      free(str);
      std::cerr << "ERROR WITH INPUT!!!\n";
      return str;
    } else {
      size += 1;
      char* newstr = static_cast< char* >(malloc(size * sizeof(char)));
      if (!newstr) {
        free(str);
        std::cerr << "ERROR WITH MEMORY!!\n";
        return newstr;
      }
      newstr = swapStr(str, newstr);
      free(str);
      str = newstr;
      str[size - 2] = enter;
      input >> enter;
    }
  }
  return str;
}
