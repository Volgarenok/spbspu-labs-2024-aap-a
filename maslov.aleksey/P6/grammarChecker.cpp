#include "grammarChecker.hpp"

bool maslov::isExpression(const char * str)
{
  auto next = hasExpression(str);
  return next && (*next == '\0');
}

const char * maslov::hasExpression(const char * str)
{

}
const char * maslov::hasMultiplier(const char * str)
{

}
const char * maslov::hasTerm(const char * str)
{

}
const char * maslov::hasIdentifier(const char * str)
{
  return maslov::hasLetter(str);
}
const char * maslov::hasDigit(const char * str)
{
  if (!str)
  {
    return str;
  }
  bool check = (*str >= '0') && (*str <= '9');
  return check ? (str + 1) : str;
}
const char * maslov::hasLetter(const char * str)
{
    if (!str)
  {
    return str;
  }
  bool check = (*str >= 'a') && (*str <= 'f');
  check = check || ((*str >= 'x') && (*str <= 'z'));
  return check ? (str + 1) : str;
}
const char * maslov::hasUnsignedInteger(const char * str)
{
  
}