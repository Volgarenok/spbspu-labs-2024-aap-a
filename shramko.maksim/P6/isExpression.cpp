#include "isExpression.hpp"

bool shramko::has_zero_or_one(const char** str)
{
  if ((**str == '0') || (**str == '1'))
  {
    (*str)++;
    return true;
  }
  return false;
}

bool shramko::has_unsigned(const char** str)
{
  if (has_zero_or_one(str))
  {
    has_unsigned(str);
    return true;
  }
  return false;
}

bool shramko::has_x_y_or_z(const char** str)
{
  if ((**str == 'x') || (**str == 'y') || (**str == 'z'))
  {
    (*str)++;
    return true;
  }
  return false;
}

bool shramko::has_letter_ID(const char** str)
{
  return has_x_y_or_z(str);
}

bool shramko::has_plus_or_minus(const char** str)
{
  if (has_expression(str))
  {
    const char* i = *str;
    if ((*i == '+') || (*i == '-'))
    {
      i++;
      if (has_plus_or_minus(&i))
      {
        *str = i;
      }
    }
    return true;
  }
  return false;
}

bool shramko::has_multiplier(const char** str)
{
  const char* i =  *str;
  if ((*(i++) == '(') && (has_plus_or_minus(&i)) && (*(i++) == ')'))
  {
    *str = i;
    return true;
  }
  return has_unsigned(str) || has_letter_ID(str);
}

bool shramko::has_expression(const char** str)
{
  const char* i = *str;
  if ((*(i++) == '(') && (has_multiplier(&i)) && (*(i++) == '+') && (has_expression(&i) && (*(i++) == ')'))
  {
    *str = i;
    return true;
  }
  if (has_multiplier(str))
  {
    if (**str == '*')
    {
      i = *str + 1;
      if (has_expressiom(&i))
      {
        *str = i;
      }
    }
    return true;
  }
  return false;
}

bool shramko::isExpression(const char* str)
{
  return has_plus_or_minus(&str) && (*str == '\0');
}
