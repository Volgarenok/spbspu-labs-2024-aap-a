#include <iostream>

std::size_t isSameSymbols(const char *const str1, const char *const str2)
{
  size_t counterArray[256] = {0};

  for (size_t i = 0; str1[i] != '\0'; ++i)
  {
    ++counterArray[str1[i]];
  }
  for (size_t i = 0; str2[i] != '\0'; ++i)
  {
    if (counterArray[str2[i]])
    {
      return 1;
      break;
    }
  }

  return 0;
}

int main()
{}
