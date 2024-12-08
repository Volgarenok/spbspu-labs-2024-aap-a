#include <iostream>
#include <input_string.hpp>
#include "expression_check.hpp"

int main()
{
  char *str1 = evstyunichev::get_string(std::cin);
  if (!str1)
  {
    std::cerr << "error\n";
    return 1;
  }
  if (!str1[0])
  {
    std::cerr << "zero input\n";
    delete[] str1;
    return 1;
  }
  std::cout << std::boolalpha << evstyunichev::check_expression(str1) << '\n';
  delete[] str1;
  return 0;
}
