#ifndef RMV_VOW_HPP
#define RMV_VOW_HPP
#include <cstddef>
#include <fstream>

namespace lebedev
{
  void removeVowels(const char* str, char* str_without_vowels);
  bool isVowel(const char c);
}
#endif
