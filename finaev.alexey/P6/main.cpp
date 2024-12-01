#include <iostream>
#include <create_str.h>
#include "check_str.h"

int main()
{
  char * str = finaev::fillStr(std::cin);
  if (str == nullptr)
  {
    std::cerr << "error create!\n";
    return 1;
  }
  if (str[0] == '\0')
  {
    free(str);
    std::cerr << "empty string!\n";
    return 1;
  }
  std::cout << std::boolalpha << finaev::checkStr(str) << "\n";
  free(str);
}
