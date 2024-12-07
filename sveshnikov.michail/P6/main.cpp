#include <iostream>
#include <ios>
#include <getline.hpp>
#include "is_real_number.hpp"

int main()
{
  char *str = nullptr;
  std::size_t len = 0;
  try
  {
    str = sveshnikov::read_str(std::cin, len);
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "ERROR: BAD_ALLOC! " << e.what() << '\n';
    return 1;
  }
  if (str[0] == '\0')
  {
    std::cerr << "ERROR: EMPTY INPUT\n";
    delete[] str;
    return 1;
  }
  std::cout << std::boolalpha << sveshnikov::isRealNumber(str) << "\n";
  delete[] str;
  return 0;
}
