#include "grammarChecker.hpp"

bool maslov::isExpression(const char * str)
{
  auto next = hasExpression(str);
  return next && (*next == '\0');
}

const char * maslov::hasExpression(const char * str)
{
  
}