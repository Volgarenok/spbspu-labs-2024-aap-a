#ifndef RECURSION_STRING_H
#define RECURSION_STRING_H
namespace alymova
{
  const char* has_e(const char* str);
  const char* has_dot(const char* str);
  const char* has_sign(const char* str);
  const char* has_number(const char* str);
  const char* has_unsigned_int(const char* str);
  const char* has_order(const char* str);
  const char* has_mantissa(const char* str);
  const char* has_double(const char* str);
  bool is_double(const char* str);
}
#endif
