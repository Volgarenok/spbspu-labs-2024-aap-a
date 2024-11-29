#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <create_str.h>
#include "string_conversion.h"

int main()
{
  char* str = finaev::fillStr(std::cin);
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
  std::cout << finaev::checkRepeat(str) << "\n";
  free(str);
}
