#include "unc_sym.h"

void getUniqueSymbols(const char* str, char* ustr)
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

void demehin::unc_sym(const char* first_str, const char* second_str, char* final_str)
{
  constexpr size_t askii_size = 128;
  char ustr1[askii_size] = {};
  char ustr2[askii_size] = {};
  getUniqueSymbols(first_str, ustr1);
  getUniqueSymbols(second_str, ustr2);
  char* ptr1 = ustr1;
  char* ptr2 = ustr2;
  char* orig_base = ptr2;
  while (*(ptr1) != '\0')
  {
    char* temp_base = orig_base;
    while (*(temp_base) != '\0')
    {
      if (*ptr1 == *temp_base)
      {
        *(final_str++) = *ptr1;
        break;
      }
      temp_base++;
    }
    ptr1++;
  }
  *final_str = '\0';
}
