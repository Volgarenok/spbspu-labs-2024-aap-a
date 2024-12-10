#include <iostream>
#include <dynamicArray.hpp>
#include "string_check.hpp"
int main()
{
  size_t capacity = 10;
  char* arr = nikonov::getLine(std::cin, capacity);
  if (!arr)
  {
    std::cerr << "ERROR: impossible to getLine\n";
    return 1;
  }
  if (*arr == '\0')
  {
    free(arr);
    std::cerr << "ERROR: an empty input\n";
    return 2;
  }
  std::cout << std::boolalpha << nikonov::is_float(arr) << '\n';
  free(arr);
  return 0;
}
