#ifndef CSTRING_HPP
#define CSTRING_HPP
#include <iostream>
namespace evstyunichev
{
  char * get_string(std::istream &, char end = '\n');
  char * resize_str(size_t, const char *old = nullptr);
  int rmv_vow(const char *, char *);
  int is_vowel(char);
  size_t cnt_not_vowel(const char *);
  size_t copy(const char *, char *);
}
#endif
