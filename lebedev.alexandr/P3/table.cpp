#include "table.hpp"
#include <cstring>


bool isNumbers(char* t)
{
  for (size_t i = 0; i < strlen(t); ++i)
  {
    if (t[i] > '9' || t[i] < '0')
    {
      return false;
    }
  }
  return true;
}
