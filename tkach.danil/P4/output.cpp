#include "strfunc.h"
#include <iostream>

void tkach::outputStr(std::ostream & out, const char* const str)
{
  for(size_t i = 0; str[i] != '\0'; ++i)
  {
    out << str[i];
  }
}
