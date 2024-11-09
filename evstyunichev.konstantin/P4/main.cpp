#include "cstrings.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
  char *str = new char[1];
  str[0] = 0;
  try
  {
    evstyunichev::getstring(str, std::cin, '\n');
  }
  catch(const std::exception &e)
  {
    std::cerr << e.what() << '\n';
    delete[] str;
    return 1;
  }
  evstyunichev::RMV_VOW(str);
  evstyunichev::output(str, std::cout);
  std::cout << '\n';
  delete[] str;
}
