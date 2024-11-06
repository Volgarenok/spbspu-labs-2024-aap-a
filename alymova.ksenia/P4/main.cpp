#include <iostream>
#include <stdexcept>
#include "string.h"
int main()
{
  size_t size = 10;
  char* str = reinterpret_cast< char* >(malloc((size + 1) * sizeof(char)));
  if (str == nullptr)
  {
    free(str);
    std::cerr << "Error: memory not allocate for string\n";
    return 1;
  }
  str[size] = '\0';
  char next = '\0';
  size_t size_now = 0;
  std::cin >> std::noskipws;
  while ((std::cin >> next) && (next != '\n'))
  {
    str[size_now] = next;
    size_now += 1;
    if (size_now == size)
    {
      size *= 2;
      try
      {
        str = alymova::increase(str, size);
      }
      catch(const std::overflow_error& e)
      {
        std::cerr << e.what() << '\n';
      }
    }
  }
  str = alymova::upper_string(str);
  std::cout << str << "\n";
  free(str);
}
