#ifndef STRING_H
#define STRING_H
#include <iostream>

namespace demehin
{
  char* copyString(const char* str, size_t size);
  void getUniqueSymbols(const char* str, char* ustr);
  char* getString(std::istream& in, char stop, char* str, size_t max_size);
  size_t unc_sym(const char* str, const char* base_str, char* final_str);
}

#endif
