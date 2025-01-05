#include <iostream>
#include <stdexcept>
#include <input_string.hpp>
#include "cstrings.hpp"

int main()
{
  char * str1 = evstyunichev::get_string(std::cin);
  if (str1 && !str1[0])
  {
    std::cerr << "zero input\n";
    delete[] str1;
    return 1;
  }
  size_t sz = evstyunichev::cnt_not_vowel(str1);
  char *str2 = evstyunichev::resize_str(sz);
  if (evstyunichev::rmv_vow(str1, str2))
  {
    std::cout << str2;
    std::cout << '\n';
  }
  else
  {
    std::cerr << "error\n";
    return 1;
  }
  delete[] str2;
  delete[] str1;
}
