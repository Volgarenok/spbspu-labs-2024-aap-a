#ifndef EXPRESSIONS_HPP
#define EXPRESSIONS_HPP
namespace gavrilova
{
  const char * is_symbol(const char * str, const  char * c);
  const char * has_identificator(const char * str);
  const char * has_digit(const char * str);
  const char * has_unsigned_int(const char * str);
  const char * has_multiplyer(const char * str);
  const char * has_term(const char * str);
  const char * has_expression (const char *  str);
  bool is_expression(const char * str);
}
#endif
