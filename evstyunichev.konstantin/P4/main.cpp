#include "cstrings.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
  char *str = new char[1];
  str[0] = 0;
  if(!(evstyunichev::getstring(str, std::cin, '\n')))
  {
    delete[] str;
    return 1;
  }
  evstyunichev::RMV_VOW(str);
  evstyunichev::output(str, std::cout);
  std::cout << '\n';
  delete[] str;
}
