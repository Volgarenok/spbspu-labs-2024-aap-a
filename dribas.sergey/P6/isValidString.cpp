#include "isValidString.hpp"
#include <cstddef>
#include <cctype>
namespace dribas
{
  const char* isChar(const char* string, char symbol);
  const char* isLetter(const char* string);
  const char* isNumber(const char* string);
  const char* isUnsignInt(const char* string);
  const char* isMultiplier(const char* string);
  const char* isTerm(const char* string);
  const char* isExpression(const char* string);
}

const char* dribas::isLetter(const char* string)
{
  if (!string) {
    return string;
  }
  char letter[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'x', 'y', 'z'};
  for (size_t i = 0; i < 9; i++) {
    if (letter[i] == *string) {
      return (string + 1);
    }
  }
  return nullptr;
}

const char* dribas::isNumber(const char* string)
{
  if (!string) {
    return string;
  }
  return (std::isdigit(*string)) ? (string + 1) : nullptr;
}

const char* dribas::isUnsignInt(const char* string)
{
  if (!string) {
    return string;
  }
  const char* next = dribas::isNumber(string);
  if (const char* countinues = dribas::isUnsignInt(next)) {
    return countinues;
  }
  return next;
}

const char* dribas::isMultiplier(const char* string)
{
  if (!string) {
    return string;
  }
  if (dribas::isUnsignInt(string)) {
    return dribas::isUnsignInt(string);
  }
  return dribas::isLetter(string);
}

const char* dribas::isTerm(const char* string)
{
  if (!string) {
    return string;
  }
  auto next = dribas::isMultiplier(string);
  if (!next) {
    return next;
  }
  if (*next == '*' || *next == '/') {
    next++;
    auto countinies = dribas::isTerm(next);
    return countinies;
  }
  return next;
}

const char* dribas::isExpression(const char* string)
{
  if (!string) {
    return nullptr;
  }
  if (*string == '\0') {
    return string;
  }
  auto next = dribas::isTerm(string);
  if (!next) {
    return next;
  }
  if (*next == '+' || *next == '-') {
    next++;
    auto countinies = dribas::isExpression(next);
    return countinies;
  }
  return next;
}
bool dribas::isValidString(const char* string)
{
  return (dribas::isExpression(string)) != nullptr;
}
