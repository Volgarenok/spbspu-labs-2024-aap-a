#include "string.h"

void demehin::getUniqueSymbols(char* str, char* ustr)
{
  char* orig_ustr = ustr;
  while (*(str) != '\0')
  {
    bool isUnique = true;
    char* temp_ustr = orig_ustr;
    while (*(temp_ustr) != '\0')
    {
      if (*str == *temp_ustr)
      {
        isUnique = false;
        break;
      }
      temp_ustr++;
    }
    if (isUnique)
    {
      *(ustr) = *(str);
      ustr++;
    }
    str++;
  }
  *ustr = '\0';
}

void demehin::unc_sym(char* str, char* base_str, char* final_str)
{
  char* orig_base = base_str;
  while (*(str) != '\0')
  {
    char* temp_base = orig_base;
    while (*(temp_base) != '\0')
    {
      if (*str == *temp_base)
      {
        *(final_str++) = *str;
        break;
      }
      temp_base++;
    }
    str++;
  }
  *final_str = '\0';
}
