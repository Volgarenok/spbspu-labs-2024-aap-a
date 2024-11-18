#include "string.h"

void demehin::getUniqueSymbols(const char* str, char* ustr)
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
}

void demehin::unc_sym(const char* str, const char* base_str, char* final_str)
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
  final_str[final_size] = '\0';
}
