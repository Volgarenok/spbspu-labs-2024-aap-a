#ifndef CSTRINGS_HPP
#define CSTRINGS_HPP
#include <iostream>
namespace evstyunichev
{
  int GetString(char *, std::istream &, char);
  int StringResize(char *, size_t);
  void RMV_VOW(char *);
  int IsVowel(char);
  void Output(char *, std::ostream &);
  size_t CntNotVowel(char *);
  char * Create(size_t);
}
#endif
