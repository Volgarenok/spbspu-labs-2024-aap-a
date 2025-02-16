#ifndef IS_EXPRESSION_HPP
#define IS_EXPRESSION_HPP
#include <cstddef>
namespace asafov
{
  bool isExpression(const char* string, size_t pos, size_t length);
  bool isBetween(char term1, char term2, char term3);
  bool isDigit(char term);
  bool isLetter(char term);
  bool isLastSym(size_t pos, size_t length, const char* string);
}
#endif
