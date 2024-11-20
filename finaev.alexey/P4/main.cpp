#include <iostream>
#include <stdexcept>
#include <cstddef>
#include "string_conversion.h"

int main()
{
  char* str = nullptr;
  size_t dl = 10;
  str = finaev::creature_empty_str(dl);
  if (str == nullptr)
  {
    std::cerr << "Error create!\n";
    return 1;
  }
  str = finaev::fill_str(std::cin, str);
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
