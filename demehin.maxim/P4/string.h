#ifndef STRING_H
#define STRING_H
#include <iostream>

namespace demehin
{
  char* copyString(char* str, size_t size);
  char* getUniqueSymbols(char* str, char* ustr);
  char* unc_sym(char* str, char* base_str, char* final_str);
  char* get(char* str, char* ustr);
}

#endif
