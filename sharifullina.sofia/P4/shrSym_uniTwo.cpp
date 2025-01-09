#include "shrSym_uniTwo.hpp"

char * sharifullina::inputString(std::istream & in, char stop)
{
  size_t capacity = 10;
  char * str = new char[capacity];
  size_t size = 0;
  char ch = '\0';
  std::noskipws(in);
  while ((in >> ch) && (ch != stop))
  {
    if (capacity == size)
    {
      capacity = capacity * 2;
      char * newstr = nullptr;
      try
      {
        newstr = new char[capacity];
      }
      catch (const std::bad_alloc & e)
      {
        delete[] str;
        std::skipws(in);
        throw;
      }
      for (size_t i = 0; i < size; ++i)
      {
        newstr[i] = str[i];
      }
      delete[] str;
      str = newstr;
    }
    str[size++] = ch;
  }
  str[size] = '\0';
  in >> std::skipws;
  return str;
}

char * sharifullina::shrSym(const char * str1, const char * str2, char * res)
{
  bool lettersFound[26] = { false };
  for (const char *ptr = str1; *ptr != '\0'; ++ptr)
  {
    if (*ptr >= 'a' && *ptr <= 'z')
    {
      lettersFound[*ptr - 'a'] = true;
    }
    else if (*ptr >= 'A' && *ptr <= 'Z')
    {
      lettersFound[*ptr - 'A'] = true;
    }
  }
  for (const char *ptr = str2; *ptr != '\0'; ++ptr)
  {
    if (*ptr >= 'a' && *ptr <= 'z')
    {
      lettersFound[*ptr - 'a'] = true;
    }
    else if (*ptr >= 'A' && *ptr <= 'Z')
    {
      lettersFound[*ptr - 'A'] = true;
    }
  }
  size_t resIndex = 0;
  for (size_t i = 0; i < 26; ++i)
  {
    if (!lettersFound[i])
    {
      res[resIndex++] = 'a' + i;
    }
  }
  res[resIndex] = '\0';
  return res;
}

char * sharifullina::uniTwo(const char * str1, const char * str2, char * res)
{
  char* ptr = res;
  const char* ptr1 = str1;
  const char* ptr2 = str2;
  while (*ptr1 != '\0' && *ptr2 != '\0')
  {
    *ptr++ = *ptr1++;
    *ptr++ = *ptr2++;
  }
  while (*ptr1 != '\0')
  {
    *ptr++ = *ptr1++;
  }
  while (*ptr2 != '\0')
  {
    *ptr++ = *ptr2++;
  }
  *ptr = '\0';
  return res;
}
