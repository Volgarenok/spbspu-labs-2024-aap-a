#include "string_utils.hpp"
#include <istream>

char* kizhin::readString(std::istream& is)
{
  size_t size = 0;
  size_t capacity = 2;
  char* inputString = static_cast<char*>(malloc(sizeof(char) * capacity));
  if (!inputString) {
    return inputString;
  }
  std::noskipws(is);
  while (is >> inputString[size] && inputString[size] != '\n') {
    ++size;
    inputString[size] = '\0';
    if (size == capacity || size == capacity - 1) {
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
  char* expandedString = static_cast<char*>(malloc(newSize * sizeof(char)));
  if (!expandedString) {
    return expandedString;
  }
  size_t i = 0;
  for (; source[i] != '\0'; ++i) {
    expandedString[i] = source[i];
  }
  expandedString[newSize - 1] = '\0';
  return expandedString;
}

void kizhin::removeLatinLetters(char* destination, const char* source)
{
  size_t k = 0;
  for (size_t i = 0; source[i] != '\0'; ++i) {
    if (!(source[i] >= 'A' && source[i] <= 'Z') && !(source[i] >= 'a' && source[i] <= 'z')) {
      destination[k++] = source[i];
    }
  }
  destination[k] = '\0';
}

