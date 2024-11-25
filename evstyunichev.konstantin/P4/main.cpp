#include <iostream>
#include <stdexcept>
#include "cstrings.hpp"

int main()
{
  char *str = new char[1];
  str[0] = 0;
  if (!(evstyunichev::GetString(str, std::cin, '\n')))
  {
    delete[] str;
    return 1;
  }
  size_t sz = evstyunichev::CntNotVowel(str);
  char *str2 = nullptr;
  int flag = StringResize(str2, sz);
  flag = evstyunichev::RMV_VOW(str, str2);
  evstyunichev::Output(str, std::cout);
  std::cout << '\n';
  delete[] str;
}
