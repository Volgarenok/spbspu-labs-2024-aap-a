#include "is_real_number.hpp"

char * petrov::hasSign(char * str)
{
  if (*str == '+' || *str == '-')
  {
    str++;
  }
  return str;
}