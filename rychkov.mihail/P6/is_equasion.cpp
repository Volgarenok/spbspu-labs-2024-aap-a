#include "is_equasion.hpp"

bool rychkov::isEquasion(const char* str)
{
  return skipEquasion(&str) && (*str == '\0');
}

bool rychkov::skipEquasion(const char** str)
{
  if (skipMultiplicationEquasion(str))
  {
    const char* temp = *str;
    if ((*temp == '+') || (*temp == '-'))
    {
      temp++;
      if (skipEquasion(&temp))
      {
        *str = temp;
      }
    }
    return true;
  }
  return false;
}

bool rychkov::skipMultiplicationEquasion(const char** str)
{
  const char* temp = *str;
  if ((*(temp++) == '(') && skipMultiplier(&temp) && (*(temp++) == '+')
      && skipMultiplicationEquasion(&temp) && (*(temp++) == ')'))
  {
    *str = temp;
    return true;
  }

  if (skipMultiplier(str))
  {
    if (**str == '*')
    {
      temp = *str + 1;
      if (skipMultiplicationEquasion(&temp))
      {
        *str = temp;
      }
    }
    return true;
  }
  return false;
}

bool rychkov::skipMultiplier(const char** str)
{
  const char* temp = *str;
  if ((*(temp++) == '(') && skipEquasion(&temp) && (*(temp++) == ')'))
  {
    *str = temp;
    return true;
  }
  return skipUnsignedInt(str) || skipVariable(str);
}

bool rychkov::skipVariable(const char** str)
{
  return skipVariableLiteral(str);
}
bool rychkov::skipVariableLiteral(const char** str)
{
  if ((**str == 'x') || (**str == 'y') || (**str == 'y'))
  {
    (*str)++;
    return true;
  }
  return false;
}

bool rychkov::skipUnsignedInt(const char** str)
{
  if (skipBinaryDigit(str))
  {
    skipUnsignedInt(str);
    return true;
  }
  return false;
}
bool rychkov::skipBinaryDigit(const char** str)
{
  if ((**str == '0') || (**str == '1'))
  {
    (*str)++;
    return true;
  }
  return false;
}
