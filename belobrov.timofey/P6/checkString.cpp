#include "checkString.hpp"

namespace belobrov
{
  const char* checkChar(const char* str, char target);
  const char* checkSign(const char* str);
  const char* isDigit(const char* str);
  const char* checkUnsigned(const char* str);
  const char* checkExponent(const char* str);
  const char* checkFraction(const char* str);
  bool validateFloat(const char* str);
}

const char* belobrov::checkChar(const char* str, char target)
{
  if (str == nullptr) {
    return nullptr;
  }
  return (*str == target) ? (str + 1) : nullptr;
}

const char* belobrov::checkSign(const char* str)
{
  if (str == nullptr) {
    return nullptr;
  }
  return (checkChar(str, '+') || checkChar(str, '-')) ? (str + 1) : str;
}

const char* belobrov::isDigit(const char* str)
{
  return (str != nullptr && *str != '\0' && (*str - '0' == *str - *str)) ? (str + 1) : nullptr;
}

const char* belobrov::checkUnsigned(const char* str)
{
  auto next = isDigit(str);
  while (next != nullptr && isDigit(next) != nullptr) {
    next = isDigit(next);
  }
  return next;
}

const char* belobrov::checkExponent(const char* str)
{
  if (str == nullptr) {
    return nullptr;
  }
  auto next = checkChar(str, 'E');
  if (next == nullptr) {
    next = checkChar(str, 'e');
  }
  if (next == nullptr) {
    return nullptr;
  }
  next = checkSign(next);
  return checkUnsigned(next);
}

const char* belobrov::checkFraction(const char* str)
{
  if (str == nullptr) {
    return nullptr;
  }
  auto next = checkUnsigned(str);
  if (next == nullptr) {
    next = str;
  }
  next = checkChar(next, '.');
  if (next == nullptr) {
    return nullptr;
  }
  return checkUnsigned(next);
}

bool belobrov::validateFloat(const char* str)
{
  if (str == nullptr || *str == '\0') {
    return false;
  }

  const char* next = checkSign(str);
  if (next == nullptr) {
    next = str;
  }

  bool hasIntPart = (checkUnsigned(next) != nullptr);
  if (hasIntPart) {
    next = checkUnsigned(next);
  }

  bool hasFrPart = false;
  if (*next == '.') {
    auto frCheck = checkUnsigned(next + 1);
    if (frCheck != nullptr) {
      hasFrPart = true;
      next = frCheck;
    }
  }

  if (hasIntPart == false && hasFrPart == false) {
    return false;
  }

  if (*next == 'E' || *next == 'e') {
    auto exponentCheck = checkExponent(next);
    if (exponentCheck == nullptr) {
      return false;
    }
    next = exponentCheck;
  }

  return (*next == '\0');
}
