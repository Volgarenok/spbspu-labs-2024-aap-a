#include <cstring>

void excludeCharacters(char* str1, const char* str2)
{
  if (!str1 || !str2)
  {
    return;
  }

  size_t j = 0;
  for (size_t i = 0; str1[i] != '\0'; ++i)
  {
    if (!std::strchr(str2, str1[i]))
    {
      str1[j++] = str1[i];
    }
  }
  str1[j] = '\0';
}
