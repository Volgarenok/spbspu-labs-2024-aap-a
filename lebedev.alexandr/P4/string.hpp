#ifndef STRING_HPP
#define STRING_HPP
#include <cstddef>
#include <fstream>

namespace lebedev
{
  void removeElement(char* str, size_t num);
  char* getLine(std::istream& in, char endChar);
  void removeVowels(char* str);
}
#endif
