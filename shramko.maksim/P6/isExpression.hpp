#ifndef ISEXPRESSION_HPP
#define ISEXPRESSION_HPP

namespace shramko
{
  const char* has_symbol(const char* str, char s);
  const char* has_x(const char* str);
  const char* has_y(const char* str);
  const char* has_z(const char* str);
  const char* has_one_or_zero(const char* str);
  const char* has_following_id(const char* str);
  const char* has_unsigned_int(const char* str);
  const char* has_multi(const char* str);
  const char* has_term(const char* str);
  const char* has_expression(const char* str);
  bool is_expression(const char* str);
}

#endif
