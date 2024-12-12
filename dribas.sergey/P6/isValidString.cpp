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
  if (*string == 'a' || *string == 'b' || *string == 'c' || *string == 'd' || *string == 'e'
    || *string == 'f' || *string == 'x' || *string == 'y' || *string == 'z') {
      return string + 1;
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
  const char* next = isNumber(string);
  if (const char* countinues = isUnsignInt(next)) {
    return countinues;
  }
  return next;
}

const char* dribas::isMultiplier(const char* string)
{
  if (!string) {
    return string;
  }
  if (isUnsignInt(string)) {
    return isUnsignInt(string);
  }
  return isLetter(string);
}

const char* dribas::isTerm(const char* string)
{
  if (!string) {
    return string;
  }
  const char * next = isMultiplier(string);
  if (!next) {
    return next;
  }
  if (*next == '*' || *next == '/') {
    next++;
    auto countinies = isTerm(next);
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
  auto next = isTerm(string);
  if (!next) {
    return next;
  }
  if (*next == '+' || *next == '-') {
    next++;
    auto countinies = isExpression(next);
    return countinies;
  }
  return next;
}
bool dribas::isValidString(const char* string)
{
  return (isExpression(string)) != nullptr;
}
