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
}
