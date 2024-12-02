#include "validInput.h"
#include <iostream>
#include <cctype>

bool cherkasov::isValidInput(const char* input)
{
  if (!input)
  {
    return false;
  }
  size_t length = 0;
  while (input[length] != '\0')
  {
    if (!std::isprint(input[length]))
    {
      return false;
    }
    ++length;
  }
  const size_t maxLength = 100;
  return length <= maxLength;
}
