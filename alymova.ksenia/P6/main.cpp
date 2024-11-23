#include <ios>
#include <iostream>
#include <dynamic_string.h>
#include "recursion_string.h"
int main()
{
  size_t size = 10;
  constexpr int ratio = 2;
  size_t size_now = 0;
  char delim = '\n';
  char* str = nullptr;
  std::cin >> std::noskipws;
  str = alymova::get_string(size, size_now, ratio, delim);
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
  std::cout << std::boolalpha << alymova::is_double(str) << "\n";
  free(str);
}
