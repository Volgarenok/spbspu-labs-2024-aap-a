#include <dynamic_string.h>
#include <iostream>
#include <ios>
#include "recursion_string.hpp"

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
    std::cerr << "Empty string\n";
    free(str);
    return 1;
  }
  str[size_now] = '\0';
  std::cout << std::boolalpha << alymova::is_double(str) << "\n";
  free(str);
}
