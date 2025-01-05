#ifndef FREQUENTSYMBOLS_H
#define FREQUENTSYMBOLS_H
#include <iostream>

namespace ivanova
{
  char frequentSymbol(const char* string);
  void twoFrequentSymbol(const char* string, char* dest);
  void twoFrequentSymbolRec(const char * string, char* dest);
}

#endif
