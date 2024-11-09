#include "string_utils.hpp"
#include <istream>

char* kizhin::readString(std::istream& is)
{
  size_t capacity = 4;
  char* inputString = static_cast<char*>(malloc(sizeof(char) * capacity));
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
  char* expandedString = static_cast<char*>(malloc(newSize * sizeof(char)));
  if (!expandedString) {
    return expandedString;
  }
  size_t i = 0;
  for (; source[i] != '\0'; ++i) {
    expandedString[i] = source[i];
  }
  expandedString[i] = '\0';
  return expandedString;
}

void kizhin::removeLatinLetters(char* destination, const char* source)
{
  if (destination == nullptr || source == nullptr) {
    return;
  }
  size_t k = 0;
  for (size_t i = 0; source[i] != '\0'; ++i, ++k) {
    bool isUpperCase = source[i] >= 'A' && source[i] <= 'Z';
    bool isLowerCase = source[i] >= 'a' && source[i] <= 'z';
    if (!(isUpperCase) && !(isLowerCase)) {
      destination[k] = source[i];
    }
  }
  destination[k] = '\0';
}

