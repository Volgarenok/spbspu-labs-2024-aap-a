#include "checkString.hpp"

namespace belobrov
{
  const char* checkChar(const char* str, char target);
  const char* checkSign(const char* str);
  const char* isDigit(const char* str);
  const char* checkUnsigned(const char* str);
  const char* checkExponent(const char* str);
  const char* checkFraction(const char* str);
}

const char* belobrov::checkChar(const char* str, char target)
{
  if (!str){
    return nullptr;
  }
  return (*str == target) ? (str + 1) : nullptr;
}

const char* belobrov::checkSign(const char* str)
{
  if (!str){
    return nullptr;
  }
  return (checkChar(str, '+') || checkChar(str, '-')) ? (str + 1) : str;
}

const char* belobrov::isDigit(const char* str)
{
  if (!str || *str == '\0') {
    return nullptr;
  }

  if (*str >= '0' && *str <= '9') {
    return str + 1;
  }

  return nullptr;
}

const char* belobrov::checkUnsigned(const char* str)
{
  if (!str) {
    return nullptr;
  }
  auto next = isDigit(str);
  if (!next) {
    return nullptr;
  }
  while (next) {
    auto continued = isDigit(next);
    if (!continued) {
      break;
    }
    next = continued;
  }
  return next;
}

const char* belobrov::checkExponent(const char* str)
{
  if (!str) {
    return nullptr;
  }
  auto next = checkChar(str, 'E');
  if (!next) {
    next = checkChar(str, 'e');
  }
  if (!next) {
    return nullptr;
  }
  next = checkSign(next);
  if (!next) {
    return nullptr;
  }

  return checkUnsigned(next);
}

const char* belobrov::checkFraction(const char* str)
{
  if (!str) {
    return nullptr;
  }
  auto next = checkUnsigned(str);
  if (!next) {
    next = str;
  }
  next = checkChar(next, '.');
  if (!next) {
    return nullptr;
  }

  return checkUnsigned(next);
}

bool belobrov::validateFloat(const char* str)
{
  if (!str || *str == '\0') {
    return false;
  }
  auto next = checkSign(str);
  bool hasIntPart = false;
  if (next) {
    auto intCheck = checkUnsigned(next);
    if (intCheck) {
      hasIntPart = true;
      next = intCheck;
    }
  }

  bool hasFrPart = false;
  if (next && *next == '.') {
    auto frCheck = checkUnsigned(next+1);
    if (frCheck) {
      hasFrPart = true;
      next = frCheck;
    } else {
      return false;
    }
  }

  if (!hasIntPart && !hasFrPart) {
    return false;
  }

  if (next && (*next == 'E' || *next == 'e')) {
    auto exponentCheck = checkExponent(next);
    if (exponentCheck) {
      next = exponentCheck;
    } else {
      return false;
    }
  }

  return next && *next == '\0';
}
