#ifndef STRING_CHEK_H
#define STRING_CHEK_H

namespace lanovenko
{
  const char* is_mantissa(const char* str);
  const char* is_symbol(const char* str, char c);
  const char* is_sign(const char* str);
  const char* is_digit(const char* str);
  const char* is_unsigned_int(const char* str);
  const char* is_E_digit(const char* str);
  bool is_valid_float_string(const char* str);
}


#endif
