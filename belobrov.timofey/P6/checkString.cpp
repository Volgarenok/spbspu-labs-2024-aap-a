#include "checkString.hpp"
#include <inputString.hpp>

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
  if (!str) {
    return nullptr;
  }
  return (*str == target) ? (str + 1) : nullptr;
}

const char* belobrov::checkSign(const char* str)
{
  if (!str) {
    return str;
  }
  return (checkChar(str, '+') || checkChar(str, '-')) ? (str + 1) : str;
}

const char* belobrov::isDigit(const char* str)
{
  if (str == nullptr) {
    return nullptr;
  }

  char c = *str;
  if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
    return str + 1;
  }

  return nullptr;
}

const char* belobrov::checkUnsigned(const char* str)
{
  if (!str) {
    return str;
  }

  auto next = isDigit(str);
  if (auto continued = checkUnsigned(next)) {
    return continued;
  }

  return next;
}

const char* belobrov::checkExponent(const char* str)
{
  if (!str) {
    return str;
  }
  auto next = checkChar(str, 'E');
  auto continued = checkSign(next);
  if (continued != nullptr) {
    return checkUnsigned(continued);
  }

  return checkUnsigned(next);
}

const char* belobrov::checkFraction(const char* str)
{
  if (!str) {
    return str;
  }
  auto next = str;
  auto continued = checkUnsigned(next);
  if (continued != nullptr) {
    next = continued;
  }
  next = checkChar(next, '.');

  return checkUnsigned(next);
}

bool belobrov::validateFloat(const char* str)
{
  if (!str) {
    return str;
  }
  auto next = checkSign(str);
  if (auto continued = checkFraction(next)) {
    return checkExponent(continued);
  }
  return checkExponent(next);
}
