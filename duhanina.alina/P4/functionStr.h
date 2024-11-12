#ifndef FUNCTIONSTR_H
#define FUNCTIONSTR_H
#include <iostream>
#include <cstddef>

namespace duhanina
{
  void shrSym(const char* str, char*& result);
  char* inputStr(std::istream& in);
  char* createNewArray(char* array, char* new_array);
}

#endif
