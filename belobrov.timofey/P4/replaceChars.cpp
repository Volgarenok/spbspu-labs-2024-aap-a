#include "replaceChars.hpp"

char* belobrov::replaceChars(char* str, char oldChar, char newChar)
{
  for (size_t i = 0; str[i] != '\0'; i++) {
    if (str[i] == oldChar) {
      str[i] = newChar;
    }
  }

  return str;
}
