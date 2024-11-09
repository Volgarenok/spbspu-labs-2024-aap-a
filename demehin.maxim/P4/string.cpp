#include "string.h"

char* demehin::copyString(char* str, size_t size)
{
  size_t temp_size = 0;
  char* new_str = nullptr;
  try
  {
    new_str = new char[size];
  }
  catch (std::bad_alloc& e)
  {
    throw;
  }

  while (str[temp_size] != '\0')
  {
    new_str[temp_size] = str[temp_size];
    temp_size += 1;
  }
  delete [] str;
  return new_str;
}

char* demehin::getUniqueSymbols(char* str, char* ustr)
{
  size_t iter1 = 0;
  size_t unique_size = 0;
  while (str[iter1] != '\0')
  {
    bool isUnique = true;
    size_t iter2 = 0;
    while (ustr[iter2] != '\0')
    {
      if (str[iter1] == ustr[iter2])
      {
        isUnique = false;
        break;
      }
      iter2 += 1;
    }
    if (isUnique)
    {
      ustr[unique_size++] = str[iter1];
    }
    iter1 += 1;
  }
  return ustr;
}

char* demehin::unc_sym(char* str, char* base_str, char* final_str)
{
  size_t iter1 = 0;
  size_t final_size = 0;
  while (str[iter1] != '\0')
  {
    size_t iter2 = 0;
    while (base_str[iter2] != '\0')
    {
      if (str[iter1] == base_str[iter2])
      {
        final_str[final_size++] = str[iter1];
        break;
      }
      iter2 += 1;

    }

    iter1 += 1;
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
      try
      {
        str = demehin::copyString(str, max_size);
      }
      catch (const std::bad_alloc& e)
      {
        throw;
      }
    }
    str[size++] = temp;
  }
  return str;
}
