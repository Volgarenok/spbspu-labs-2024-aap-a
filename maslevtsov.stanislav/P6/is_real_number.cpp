#include "is_real_number.hpp"

const char* maslevtsov::hasSymbol(const char* str, char symbol)
{
  if (!str)
  {
    return str;
  }
  return (*str == symbol) ? (str + 1) : nullptr;
}

bool maslevtsov::isRealNumber(const char* str)
{}
