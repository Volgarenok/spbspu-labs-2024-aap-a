#ifndef STRING_FUNCTIONS_HPP
#define STRING_FUNCTIONS_HPP
#include <cstddef>
namespace asafov
{
  bool isLetter(char ch);
  int countUniqLetters(const char* string, size_t lenght);
  char* getUnusedLetters(const char* string, size_t length);
}
#endif
