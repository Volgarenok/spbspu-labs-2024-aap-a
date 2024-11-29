#include "isValidString.hpp"

namespace dribas
{
  char* isChar(const char* string, char symbol);
  char* isLetter(const char* string);
  char* isNumber(const char* string);
  char* isUnsignInt(const char* string);
}

char* dribas::isChar(const char* string, char symbol)
{
  if (!string) {
    return string;
  }
  return (*string == symbol) ? (string + 1) : nullptr;
}

char* dribas::isLetter(const char* string)
{
  if (!string) {
    return string;
  }
  char letter[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'x', 'y', 'z'};
  for (size_t i = 0; i < 9; i++) {
    if (dribas::isChar(string, letter[i])) {
      return (string + 1);
    }
  return nullptr;
  }
}

char* dribas::isNumber(const char* string)
{
  if (!string) {
    return string;
  }
  return (std::isdigit(*string)) ? (string + 1) : nullptr;
}

char* dribas::isUnsignInt(const char* string)
{
  if (!string) {
    return string;
  }
  auto next = isNumber(string);
  if (auto countinues = isNumber(next)) {
    return countinues;
  }
  return next;
}
