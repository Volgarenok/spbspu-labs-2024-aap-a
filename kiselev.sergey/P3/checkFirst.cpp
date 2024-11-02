#include "checkFirst.h"
#include <cctype>
#include <cstring>

bool kiselev::checkFirst(char* argv)
{
  for (size_t i = 0; argv[i] != '\0'; ++i)
  {
    if (!std::isdigit(argv[i]))
    {
      return false;
    }
  }
  return true;
}

