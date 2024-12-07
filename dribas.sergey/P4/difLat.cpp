#include "difLat.hpp"
#include <cctype>

size_t dribas::difLat(const char* str)
{
  size_t result = 0;
  const char* ptrstr = str;
  while (*ptrstr != '\0') {
    if (std::isalpha(*ptrstr)) {
      bool check = true;
      const char* prevptr = ptrstr - 1;
      while (prevptr >= str) {
        if (*ptrstr == *prevptr) {
          check = false;
          break;
        }
        prevptr--;
      }
      if (check) {
        result++;
      }
    }
    ptrstr++;
  }
  return result;
}

