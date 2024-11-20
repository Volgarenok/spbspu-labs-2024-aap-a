#include "isexpression.hpp"

bool brevnov::isExpreession(const char * str)
{
  if (!str)
  {
    return false;
  }
  return false;
}

const char * brevnov::isLetter(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  return ((*str == 'x') || (*str == 'y') || (*str == 'z')) ? (str + 1) : nullptr;
}

const char * brevnov::isDigit(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  return ((*str == '1') || (*str == '0')) ? (str + 1) : nullptr;
}
