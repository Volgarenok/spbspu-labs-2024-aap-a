#include "fu_string.h"
#include <cstdlib>
#include <cstring>

char* hismatova::remakeString(char* str, size_t size2)
{
  char* str2 = reinterpret_cast<char*>(malloc(size2 * sizeof(char)));
  if (str2 == nullptr)
  {
    free(str);
    return nullptr;
  }
  for (size_t i = 0; str[i] != '\0'; i++)
  {
    str2[i] = str[i];
  }
  return str2;
}

char* hismatova::uniqueChar(const char* str1, const char* str2)
{
  bool arr[256] = {0};
  size_t count = 0;
  for (size_t i = 0; str1[i] != '\0'; ++i)
  {
    if ((str1[i] >= 'A' && str1[i] <= 'Z') || (str1[i] >= 'a' && str1[i] <= 'z'))
    {
      arr[str1[i] | 32] = true;
    }
  }
  for (size_t i = 0; str2[i] != '\0'; ++i)
  {
    if ((str2[i] >= 'A' && str2[i] <= 'Z') || (str2[i] >= 'a' && str2[i] <= 'z'))
    {
      arr[str2[i] | 32] = true;
    }
  }
  for (size_t i = 0; i < 256; ++i)
  {
    if (arr[i])
    {
      count++;
    }
  }
  char* result = reinterpret_cast<char*>(malloc(count + 1));
  if (result == nullptr)
  {
    return nullptr;
  }
  size_t ind = 0;
  for (size_t i = 0; i < 256; ++i)
  {
    if (arr[i])
    {
      result[ind++] = static_cast<char>(i);
    }
  }
  result[ind] = '\0';
  return result;
}
