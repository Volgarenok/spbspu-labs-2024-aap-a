#include "str_functions.hpp"

int main()
{
  constexpr const char *str2 = "def ";
  char *str1 = nullptr;
  try
  {
    str1 = abramov::getStr(std::cin);
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Memory fail\n";
    return 2;
  }
  str1 = abramov::unionStrs(str1, str2);
  size_t i = 0;
  while (str[i] != '\0')
  {
    std::cout << str1[i];
    ++i;
  }
  std::cout << "\n";
  delete[] str1;
}
