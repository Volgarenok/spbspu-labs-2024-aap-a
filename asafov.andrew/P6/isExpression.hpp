#ifndef IS_EXPRESSION_HPP
#define IS_EXPRESSION_HPP
#include <cstddef>
namespace asafov
{
  bool isExpression(const char* string, size_t pos, size_t length);
  bool isBetween(char letter, char begin, char end);
  bool isDigit(char term);
  bool isLetter(char term);
  bool isLastSym(size_t pos, size_t length, const char* string);
}
#endif
