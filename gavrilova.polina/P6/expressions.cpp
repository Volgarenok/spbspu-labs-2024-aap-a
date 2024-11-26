#include <iostream>
const char * has_multiplyer(const char * str);
const char * has_term(const char * str);
const char * has_expression (const char *  str);

const char * is_symbol(const char * str, const  char * c)
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
const char * has_identificator(const char * str)
{
  if (!str) {
    return nullptr;
  }

  return is_symbol(str, "xyz");
}
const char * has_digit(const char * str)
{
  if (!str) {
    return nullptr;
  }
  return is_symbol(str, "01");
}
const char * has_unsigned_int(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  auto next = has_digit(str);
  auto continues = has_unsigned_int(next);
  if (continues) {
    return continues;
  }
  return next;
}
const char * has_multiplyer(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  auto next = is_symbol(str, "(");
  next = has_expression(next);
  next = is_symbol(next, ")");
  if (next) {
    return next;
  }
  next = has_unsigned_int(str);
  if (next) {
    return next;
  }
  next = has_identificator(str);
  return next;
}
const char * has_term(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  auto next = has_multiplyer(str);
  if (next) {
    auto continues = is_symbol(next,"*");
    return (continues) ? has_term(continues) : next;
  } else {
    next = is_symbol(str, "(");
    next = has_multiplyer(next);
    next = is_symbol(next, "+");
    next = has_term(next);
    next = is_symbol(next, ")");
    return next;
  }
}
const char * has_expression (const char *  str)
{
  auto next = has_term(str);
  next = is_symbol(next, "-+");
  next = has_expression(next);
  return next;
}
bool is_expression(const char * str)
{
  auto next = has_expression(str);
  return next && (*next == '\0');
}
int main()
{
  const char * str = "(x+x)";
  if (has_multiplyer(str)) {
    std::cout << "true";
  } else {
    std::cout << "false";
  }
}
