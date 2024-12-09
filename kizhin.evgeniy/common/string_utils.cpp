#include "string_utils.hpp"
#include <istream>

char* kizhin::readString(std::istream& is)
{
  size_t capacity = 4;
  char* inputString = static_cast< char* >(malloc(sizeof(char) * capacity));
  if (!inputString) {
    return inputString;
  }
  inputString[0] = '\0';
  std::noskipws(is);
  char current = {};
  for (size_t size = 0; is >> current && current != '\n'; ++size) {
    inputString[size] = current;
    inputString[size + 1] = '\0';
    if (size + 2 == capacity) {
      capacity *= 2;
      char* temp = expandString(inputString, capacity);
      free(inputString);
      if (!temp) {
        return temp;
      }
      inputString = temp;
    }
  }
  return inputString;
}

char* kizhin::expandString(const char* source, size_t newSize)
{
  char* expandedString = static_cast< char* >(malloc(newSize * sizeof(char)));
  if (!expandedString) {
    return expandedString;
  }
  char* k = expandedString;
  for (const char* i = source; *i != '\0'; ++i, ++k) {
    *k = *i;
  }
  *k = '\0';
  return expandedString;
}

