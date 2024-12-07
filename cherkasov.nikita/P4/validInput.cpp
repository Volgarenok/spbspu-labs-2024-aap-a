#include "validInput.h"
#include <iostream>
#include <cctype>

bool cherkasov::isValidInput(const char* input)
{
  if (!input)
  {
    std::cerr << "Error: The string is empty.\n";
    return false;
  }
  size_t length = 0;
  while (input[length] != '\0')
  {
    if (!std::isprint(input[length]))
    {
      std::cerr << "Error:no char string.\n";
      return false;
    }
    ++length;
  }
  const size_t maxLength = 1000;
  if (length > maxLength)
  {
    std::cerr << "Error: line max leght." << maxLength << "\n";
    return false;
  }
  return true;
}
