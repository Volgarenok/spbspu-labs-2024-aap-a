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

//char* (char* str, char* base_str, char* final_str)
//{
  //size_t iter1 = 0;
  //size_t iter2 = 0;
  //size_t iter3 = 0;
//}

char* demehin::getUniqueSymbols(char* str, char* ustr)
{
  size_t iter = 0;
  size_t unique_size = 0;
  while (str[iter] != '\0')
  {
    bool isUnique = true;

    for (size_t i = 0; i < 128; ++i)
    {
      if (str[iter] == str[i] && iter != i)
      {
        isUnique = false;
        break;
      }
    }

    if (isUnique)
    {
      ustr[unique_size++] = str[iter];
    }
    iter += 1;
  }

  return ustr;
}
