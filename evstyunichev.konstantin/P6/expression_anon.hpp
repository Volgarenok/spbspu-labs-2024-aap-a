#ifndef EXPRESSION_ANON_HPP
#define EXPRESSION_ANON_HPP
namespace
{
  const char * is_factor_correct(const char *, int prev = 3);
  const char * is_term_correct(const char *, int prev = 1);
  const char * is_expression_correct(const char *, int prev = 1, bool OpenFlag = 0);
  bool is_letter(char, char cur = 'a');
  bool is_digit(char, char cur = '0');
  bool is_basic_symbol(char);
  bool is_sign(char);
}
#endif
