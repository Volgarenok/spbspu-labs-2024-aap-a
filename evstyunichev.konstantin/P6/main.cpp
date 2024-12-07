#include <iostream>
#include <input_string.hpp>
#include "recursion.hpp"

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
    return 1;
  }
  bool flag = (evstyunichev::is_expression_correct(str1) != nullptr);
  std::cout << std::boolalpha << flag << '\n';
  delete[] str1;
  return 0;
}
