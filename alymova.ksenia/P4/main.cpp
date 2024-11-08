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
    free(str);
    std::cerr << "Error: memory not allocate for string\n";
    return 1;
  }
  char next = '\0';
  size_t size_now = 0;
  std::cin >> std::noskipws;
  while ((std::cin >> next) && (next != '\n'))
  {
    str[size_now] = next;
    size_now += 1;
    if (size_now == size)
    {
      size *= ratio;
      char* str_new = alymova::create(size);
      if (str_new == nullptr)
      {
        free(str);
        free(str_new);
        std::cerr << "Error: memory not allocate for string\n";
        return 1;
      }
      str = alymova::increase_string(str, str_new);
    }
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
