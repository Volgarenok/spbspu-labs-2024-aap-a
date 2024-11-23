#include <iostream>
#include <cstddef>
#include <dynamic_string.h>
#include "reform.h"
int main()
{
  constexpr int ratio = 2;
  size_t capacity = 10, size = 0;
  char* str = alymova::get_string(std::cin, capacity, size, ratio, '\n');
  if (str == nullptr)
  {
    std::cerr << "Error: memory not allocate for string or incorrect parameters\n";
    return 1;
  }
  if (size == 0)
  {
    free(str);
    std::cerr << "Empty string\n";
    return 1;
  }
  char* str_res = reinterpret_cast< char* >(malloc((size + 1) * sizeof(char)));
  if (str_res == nullptr)
  {
    free(str);
    std::cerr << "Error: memory not allocate for string\n";
    return 1;
  }
  str_res[size] = '\0';
  str_res = alymova::upper_string(str, str_res);
  std::cout << str_res << "\n";
  free(str);
  free(str_res);
}
