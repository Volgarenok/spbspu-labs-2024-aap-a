#ifndef STRFUNC_H
#define STRFUNC_H

#include <cstddef>
#include <fstream>

namespace tkach {
  int getMemoryForStr(char*& s, size_t& capacity);
  std::istream& inputStr(std::istream& in, char*& str, size_t& capacity);
  void outputStr(std::ostream & out, char* str);
}

#endif
