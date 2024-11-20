#include <iostream>
#include <stdexcept>
#include <cstddef>
#include "string_conversion.h"

int main()
{
  char* str = nullptr;
  str = finaev::fill_str(std::cin);
  if (str == nullptr)
  {
    std::cerr << "error create!\n";
    return 1;
  }
  int res = 2;
  res = finaev::is_repeat(str);
  std::cout << res << "\n";
  free(str);
}
