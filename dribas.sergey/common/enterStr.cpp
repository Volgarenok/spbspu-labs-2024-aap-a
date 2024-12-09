#include "enterStr.hpp"
#include <iostream>
#include <cstddef>

char* displacementStr(const char* oldstr, char* newstr) {
  size_t i = 0;
  for(; *(oldstr + i) != '\0'; i++) {
    *(newstr + i) = *(oldstr + i);
  }
  *(newstr + i + 1) = '\0';
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
  *str = lastSymbol;
  std::noskipws(input);
  input >> enter;
  while (enter != lastStrSymbol) {
    if (!input) {
      free(str);
      std::skipws(input);
      return nullptr;
    } else {
      size++;
      char* newstr = static_cast< char* >(malloc(size * sizeof(char)));
      if (!newstr) {
        free(str);
        std::skipws(input);
        return newstr;
      }
      newstr = displacementStr(str, newstr);
      free(str);
      str = newstr;
      *(newstr + size - 2) = enter;
      input >> enter;
    }
  }
  std::skipws(input);
  return str;
}

