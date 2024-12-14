#include "is_expression.hpp"
#include <cctype>

namespace kizhin {
  const char* isExpressionImpl(const char* position);
  const char* isTerm(const char* position);
  const char* isFactor(const char* position);
  const char* isNumber(const char* position);
  const char* isIdentifier(const char* position);
  const char* isIdentifier(const char* position, const char* valid);
}

bool kizhin::isExpression(const char* string)
{
  return isExpressionImpl(string);
}

const char* kizhin::isExpressionImpl(const char* position)
{
  position = isTerm(position);
  if (!position) {
    return nullptr;
  }
  if (*position == '+' || *position == '-') {
    return isExpressionImpl(++position);
  }
  return position;
}

const char* kizhin::isTerm(const char* position)
{
  position = isFactor(position);
  if (!position) {
    return nullptr;
  }
  if (*position == '*' || *position == '/') {
    return isTerm(++position);
  }
  return position;
}

const char* kizhin::isFactor(const char* position)
{
  if (*position == '(') {
    position = isExpressionImpl(++position);
    if (position && *position == ')') {
      return ++position;
    }
    return nullptr;
  }
  const char* tmp = isNumber(position);
  if (tmp) {
    return tmp;
  }
  return isIdentifier(position);
}

const char* kizhin::isNumber(const char* position)
{
  if (!std::isdigit(*position)) {
    return nullptr;
  }
  return isNumber(position + 1) ? position + 1 : position;
}

const char* kizhin::isIdentifier(const char* position)
{
  const char* valid = "abcxyz";
  return isIdentifier(position, valid);
}

const char* kizhin::isIdentifier(const char* position, const char* valid)
{
  if (*valid == '\0') {
    return nullptr;
  }
  if (*position == *valid) {
    return ++position;
  }
  return isIdentifier(position, ++valid);
}

