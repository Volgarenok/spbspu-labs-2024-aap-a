#include "recfunc.h"
#include <iostream>
#include <cctype>

namespace averenkov
{
  bool hasExpression(char* str, size_t& index);
  bool hasTerm(char* str, size_t& index);
  bool hasFactor(char* str, size_t& index);
}

bool averenkov:hasExpession(char* str, size_t& index)
{
  if (!averenkov:hasTerm(str, index))
  {
    return false;
  }
  while (str[index] == '+' || str[index] == '-')
  {
    index++;
    if (!averenkov:hasExpession(str, index))
    {
      return false;
    }
  }
  return true;
}

bool averenkov:hasTerm(char* str, size_t& index)
{
  if (!averenkov::hasFactor(str, index))
  {
    return false;
  }
  while (str[index] == '*' || str[index] == '/')
  {
    index++;
    if (!averenkov:hasTerm(str, index))
    {
      return false;
    }
  }
  return true;
}

bool averenkov::hasFactor(char* str, size_t& index)
{
  if (str[index] == '(')
  {
    index++;
    if (!averenkov:hasExpession(str, index))
    {
      return false;
    }
    if (str[index] == ')')
    {
      index++;
      return true;
    }
    return false;
  }
  else if (isdigit(str[index]))
  {
    while (isdigit(str[index]))
    {
      index++;
    }
    return true;
  }
  return false;
}

bool averenkov::parse(char* str)
{
  size_t index = 0;
  if (averenkov:hasExpession(str, index) && str[index] == '\0')
  {
    return true;
  }
  return false;
}

