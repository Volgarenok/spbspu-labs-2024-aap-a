#include "validInput.h"
#include <cctype>
#include <cstddef>

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
  const size_t maxLength = 1000;
  if (length > maxLength)
  {
    return false;
  }
    return true;
}
