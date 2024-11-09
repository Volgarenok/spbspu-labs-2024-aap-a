#ifndef CSTRINGS_HPP
#define CSTRINGS_HPP
#include <iostream>
namespace evstyunichev
{
  void getstring(char *, std::istream &, char);
  void string_resize(char *, size_t);
  void RMV_VOW(char *);
  int isgl(char);
  void output(char *, std::ostream &);
}
#endif
