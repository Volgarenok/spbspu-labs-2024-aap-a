#include "string.h"
//
char* demehin::copyString(const char* str, size_t size)
{
  size_t temp_size = 0;
  char* new_str = nullptr;
  new_str = new char[size];

  while (str[temp_size] != '\0')
  {
    new_str[temp_size] = str[temp_size];
    temp_size += 1;
  }
  delete [] str;
  return new_str;
}

char* demehin::getUniqueSymbols(const char* str, char* ustr)
{
  size_t iterator1 = 0;
  size_t unique_size = 0;
  while (str[iterator1] != '\0')
  {
    bool isUnique = true;
    size_t iterator2 = 0;
    while (ustr[iterator2] != '\0')
    {
      if (str[iterator1] == ustr[iterator2])
      {
        isUnique = false;
        break;
      }
      iterator2 += 1;
    }
    if (isUnique)
    {
      ustr[unique_size++] = str[iterator1];
    }
    iterator1 += 1;
  }
  return ustr;
}

char* demehin::unc_sym(const char* str, const char* base_str, char* final_str)
{
  size_t iterator1 = 0;
  size_t final_size = 0;
  while (str[iterator1] != '\0')
  {
    size_t iterator2 = 0;
    while (base_str[iterator2] != '\0')
    {
      if (str[iterator1] == base_str[iterator2])
      {
        final_str[final_size++] = str[iterator1];
        break;
      }
      iterator2 += 1;
    }

    iterator1 += 1;
  }
  return final_str;
}

char* demehin::getString(std::istream& in, char stop, char* str, size_t max_size)
{
  size_t size = 0;
  char temp = '\0';
  std::noskipws(in);

  while ((in >> temp) && (temp != stop))
  {
    if (size == max_size)
    {
      max_size *= 2;
      str = demehin::copyString(str, max_size);
    }
    str[size++] = temp;
  }
  return str;
}
