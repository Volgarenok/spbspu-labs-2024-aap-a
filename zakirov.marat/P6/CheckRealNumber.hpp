#ifndef CHECKREALNUMBER_HPP
#define CHECKREALNUMBER_HPP
namespace zakirov
{
  const char * compare_literals(const char * line, char literal);
  const char * check_sign(const char * line);
  const char * check_integer(const char * line);
  const char * check_uinteger(const char * line);
  const char * check_sinteger(const char * line);
  const char * check_order(const char * line);
  const char * check_mantissa(const char * line);
}

#endif
