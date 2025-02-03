#include <iostream>
#include "expressions.hpp"

namespace gavrilova {
  const char * is_symbol(const char * str, char c);
  const char * has_identificator(const char * str);
  const char * has_digit(const char * str);
  const char * has_unsigned_int(const char * str);
  const char * has_multiplyer(const char * str);
  const char * has_term(const char * str);
  const char * has_expression (const char *  str);
}

const char * gavrilova::is_symbol(const char * str, char c)
{
  if (!str) {
    return nullptr;
  }
  return (*str == c) ? (str + 1) : nullptr;
}

const char * gavrilova::has_identificator(const char * str)
{
  if (!str) {
    return nullptr;
  }
  return ((is_symbol(str, 'x')) || is_symbol(str, 'y') || is_symbol(str, 'z')) ? (str + 1) : nullptr;
}

const char * gavrilova::has_digit(const char * str)
{
  if (!str) {
    return nullptr;
  }
  return (is_symbol(str, '0') || is_symbol(str, '1')) ? (str + 1) : nullptr;
}

const char * gavrilova::has_unsigned_int(const char * str)
{
  if (!str) {
    return nullptr;
  }
  auto next = has_digit(str);
  auto continues = has_unsigned_int(next);
  if (continues) {
    return continues;
  }
  return next;
}

const char * gavrilova::has_multiplyer(const char * str)
{
  if (!str) {
    return nullptr;
  }
  auto next = has_unsigned_int(str);
  if (next) {
    return next;
  }
  next = has_identificator(str);
  if (next) {
    return next;
  }
  next = is_symbol(str, '(');
  next = has_expression(next);
  next = is_symbol(next, ')');
  return next;
}

const char * gavrilova::has_term(const char * str)
{
  if (!str) {
    return nullptr;
  }
  auto next = has_multiplyer(str);
  if (next && !is_symbol(next, '*')) {
    return next;
  }
  next = is_symbol(next, '*');
  if (next) {
    auto continues = has_term(next);
    if (continues) {
      return continues;
    }
    return next;
  } else {
    next = is_symbol(str, '(');
    next = has_multiplyer(next);
    next = is_symbol(next, '+');
    next = has_term(next);
    next = is_symbol(next, ')');
    return next;
  }
}

const char * gavrilova::has_expression (const char *  str)
{
  if (!str) {
    return nullptr;
  }
  auto next = has_term(str);
  auto continiues = is_symbol(next, '+');
  if (!continiues) {
    continiues = is_symbol(next, '-');
    if (!continiues) {
      return next;
    }
    next = has_expression(continiues);
    return next;
  }
  next = has_expression(continiues);
  return next;
}

bool gavrilova::is_expression(const char * str)
{
  auto next = has_expression(str);
  return next && (*next == '\0');
}

