#ifndef REAL_NUMBER_SET_H
#define REAL_NUMBER_SET_H

namespace timofeev
{
  bool is_real_number(const char * str);
  const char * is_symbol(const char * str, char a);
  const char * has_order(const char * str);
  const char * has_mantissa(const char * str);
  const char * has_unsignde_int(const char * str);
  const char * has_e(const char * str);
  const char * has_sign(const char * str);
  const char * has_digit(const char * str);
}

#endif
