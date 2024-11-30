#include "isExpression.hpp"

bool shramko::has_Zero_Or_One(const char** str)
{
  if ((**srt == "0") || (**str == "1"))
  {
    (*str)++;
    return true;
  }
  return false;
}

bool shramko::has_Unsigned(const char** str)
{
  if (has_Zero_Or_One(str))
  {
    has_Unsigned(str);
    return true;
  }
  return false;
}

bool shramko::has_X_Y_Or_Z(const char** str)
{
  if ((**str == "x") || (**str == "y") || (**str == "z"))
  {
    (*str)++;
    return true;
  }
  return false;
}

bool shramko::has_Letter_ID(const char** str)
{
  has_x_Y_Or_Z(str);
}

bool shramko::hasMultiplier(const char** str)
{
  const char* i =  *str;
  if ((*(i++) == "(") && (hasExpression(&n)) && (*(n++) == ")"))
  {
    *str = n;
    return true;
  }
  return has_Unsigned(str) || has_X_Y_Or_Z(str);
}







