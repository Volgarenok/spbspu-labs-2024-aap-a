#include "shrSym_uniTwo.hpp"

char * sharifullina::inputString(std::istream & in, char stop)
{
  constexpr size_t capacity = 10;
  char * str = new char[capacity];
  size_t size = 0;
  char ch = '\0';
  std::noskipws(in);
  while ((in >> ch) && (ch != stop))
  {
    if (capacity == size)
    {
      char * newstr = nullptr;
      try
      {
        newstr = new char[capacity * 2];
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

char * sharifullina::shrSym(const char * str1, const char * str2)
{
  char * res = new char[27];
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
char * sharifullina::uniTwo(const char * str1, const char * str2)
{
  size_t length1 = 0;
  while (str1[length1] != '\0')
  {
    length1++;
  }
  size_t length2 = 0;
  while (str2[length2] != '\0')
  {
    length2++;
  }
  char *res = new char[length1 + length2 + 1];
  while (*str1 != '\0' && *str2 != '\0')
  {
    *res++ = *str1++;
    *res++ = *str2++;
  }
  while (*str1 != '\0')
  {
    *res++ = *str1++;
  }
  while (*str2 != '\0')
  {
    *res++ = *str2++;
  }
  *res = '\0';
  return res;
}
