#include <iostream>
#include <dynamic.h>
#include "recursion_float.h"

int main()
{
  size_t size_str = 20;
  size_t size_str_now = 0;
  char * str = komarova::read(std::cin, size_str, size_str_now, '\n');
  if (str == nullptr)
  {
    std::cerr << "No memory allocated or incorrect parameters \n";
    return 1;
  }
  if (size_str_now == 0)
  {
    free(str);
    std::cerr << "Empty string \n";
    return 1;
  }
  std::cout << std::boolalpha << komarova::is_float_lit(str) << "\n";
  free(str);
}
