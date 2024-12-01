#include "validInput.h"
#include <iostream>
#include <cctype>

bool cherkasov::isValidInput(const char* input)
{
  if (!input)
  {
    return false;
  }
  for (const char* ptr = input; *ptr != '\0'; ++ptr)
  {
    if (!std::isprint(*ptr))
    {
      return false;
    }
  }
  return true;
}
