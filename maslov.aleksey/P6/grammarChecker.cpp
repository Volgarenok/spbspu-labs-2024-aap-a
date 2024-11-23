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

}
const char * maslov::isDigit(const char * str)
{

}
const char * maslov::isLetter(const char * str)
{
  
}