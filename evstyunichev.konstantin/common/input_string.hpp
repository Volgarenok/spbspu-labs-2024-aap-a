#ifndef INPUT_STRING_HPP
#define INPUT_STRING_HPP
#include <iostream>
namespace evstyunichev
{
  char * get_string(std::istream &, char end = '\n');
  char * resize_str(size_t, const char *old = nullptr);
  size_t copy(const char *, char *);
}
#endif
