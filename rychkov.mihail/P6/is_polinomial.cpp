#include "is_polinomial.hpp"

namespace rychkov
{
  bool skipPolinomial(const char** str);
  bool skipMultiplicationPolinomial(const char** str);
  bool skipMultiplier(const char** str);
  bool skipVariable(const char** str);
  bool skipVariableLiteral(const char** str);
  bool skipUnsignedInt(const char** str);
  bool skipBinaryDigit(const char** str);
}

bool rychkov::isPolinomial(const char* str)
{
  return skipPolinomial(&str) && (*str == '\0');
}

bool rychkov::skipPolinomial(const char** str)
{
  if (skipMultiplicationPolinomial(str))
  {
    const char* temp = *str;
    if ((*temp == '+') || (*temp == '-'))
    {
      temp++;
      if (skipPolinomial(&temp))
      {
        *str = temp;
      }
    }
    return true;
  }
  return false;
}

bool rychkov::skipMultiplicationPolinomial(const char** str)
{
  const char* temp = *str;
  if ((*(temp++) == '(') && skipMultiplier(&temp) && (*(temp++) == '+')
      && skipMultiplicationPolinomial(&temp) && (*(temp++) == ')'))
  {
    *str = temp;
    return true;
  }

  if (skipMultiplier(str))
  {
    if (**str == '*')
    {
      temp = *str + 1;
      if (skipMultiplicationPolinomial(&temp))
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
  if ((*(temp++) == '(') && skipPolinomial(&temp) && (*(temp++) == ')'))
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
  if ((**str == 'x') || (**str == 'y') || (**str == 'z'))
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
