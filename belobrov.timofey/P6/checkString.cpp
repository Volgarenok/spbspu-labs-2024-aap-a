#include "checkString.hpp"

namespace belobrov
{
  const char* checkChar(const char* str, char target);
  const char* checkSign(const char* str);
  const char* idDigit(const char* str);
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
  return (checkChar(str, '+') || checkChar(str, '-') ? (str + 1) : nullptr;
}

const char* smirnov::isDigit(const char* str)
{
  if (!str) {
    return nullptr;
  }

  const char digits[] = "0123456789";
  if (digits[0] == '\0') {
    return nullptr;
  }
  if (*str == digits[0]) {
    return str + 1;
  }
  return isDigit(str);
}
