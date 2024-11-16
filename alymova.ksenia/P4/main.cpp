#include <iostream>
#include <stdexcept>
#include <cstddef>
#include "dynamic_string.h"
int main()
{
  size_t size = 10;
  constexpr int ratio = 2;
  char* str = alymova::create(size);
  if (str == nullptr)
  {
    std::cerr << "Error: memory not allocate for string\n";
    return 1;
  }
  size_t size_now = 0;
  char delim = '\n';
  std::cin >> std::noskipws;
  str = alymova::get_string(str, size, size_now, ratio, delim);
  if (str == nullptr)
  {
    std::cerr << "Error: memory not allocate for string\n";
    return 1;
  }
  if (size_now == 0)
  {
    free(str);
    std::cerr << "Empty string\n";
    return 1;
  }
  str[size_now] = '\0';
  str = alymova::upper_string(str);
  std::cout << str << "\n";
  free(str);
}
