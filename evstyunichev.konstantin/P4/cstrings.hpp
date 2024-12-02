#ifndef CSTRING_HPP
#define CSTRING_HPP
#include <iostream>
namespace evstyunichev
{
  char * get_string(std::istream &, char);
  char * resize_str(size_t, char *str = nullptr);
  int rmv_vow(char *, char *);
  int is_vowel(char);
  void output(char *, std::ostream &);
  size_t cnt_not_vowel(char *);
  char * create(size_t);
  void copy(char *, char *);
}
#endif
