#include <iostream>
#include "expressions.hpp"

namespace gavrilova {
  const char * is_symbol(const char * str, const  char * c);
  const char * has_identificator(const char * str);
  const char * has_digit(const char * str);
  const char * has_unsigned_int(const char * str);
  const char * has_multiplyer(const char * str);
  const char * has_term(const char * str);
  const char * has_expression (const char *  str);
}

const char * gavrilova::is_symbol(const char * str, const  char * c)
{
  if (!str) {
    return nullptr;
  }
  for (size_t i = 0; c[i] != '\0'; ++i) {
    if (*str == c[i]) {
      return (str + 1);
    }
  }
  return nullptr;
}

const char * gavrilova::has_identificator(const char * str)
{
  if (!str) {
    return nullptr;
  }
  return gavrilova::is_symbol(str, "xyz");
}

const char * gavrilova::has_digit(const char * str)
{
  if (!str) {
    return nullptr;
  }
  return gavrilova::is_symbol(str, "01");
}

const char * gavrilova::has_unsigned_int(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  auto next = gavrilova::has_digit(str);
  auto continues = gavrilova::has_unsigned_int(next);
  if (continues) {
    return continues;
  }
  return next;
}

const char * gavrilova::has_multiplyer(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  auto next = gavrilova::has_unsigned_int(str);
  if (next) {
    return next;
  }
  next = gavrilova::has_identificator(str);
  if (next) {
    return next;
  }
  next = gavrilova::is_symbol(str, "(");
  next = gavrilova::has_expression(next);
  next = gavrilova::is_symbol(next, ")");
  return next;
}

const char * gavrilova::has_term(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  auto next = gavrilova::has_multiplyer(str);
  if (next && !gavrilova::is_symbol(next,"*")) {
    return next;
  }
  next = gavrilova::is_symbol(next,"*");
  if (next) {
    auto continues = gavrilova::has_term(next);
    if (continues) {
      return continues;
    }
    return next;
  } else {
    next = gavrilova::is_symbol(str, "(");
    next = gavrilova::has_multiplyer(next);
    next = gavrilova::is_symbol(next, "+");
    next = gavrilova::has_term(next);
    next = gavrilova::is_symbol(next, ")");
    return next;
  }
}

const char * gavrilova::has_expression (const char *  str)
{
  if (!str)
  {
    return nullptr;
  }
  auto next = gavrilova::has_term(str);
  auto continiues = gavrilova::is_symbol(next, "-+");
  if (!continiues) {
    return next;
  }
  next = gavrilova::has_expression(continiues);
  return next;
}

bool gavrilova::is_expression(const char * str)
{
  auto next = gavrilova::has_expression(str);
  return next && (*next == '\0');
}

