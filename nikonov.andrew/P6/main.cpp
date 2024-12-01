#include <iostream>
#include <dynamicArray.hpp>
#include "string_check.hpp"
int main()
{
  size_t capacity = 10;
  char* arr = nikonov::getLine(std::cin, capacity);
  if (!arr || *arr == '\0')
  {
    return 1;
  }
  std::cout << std::boolalpha << nikonov::is_float(arr) << '\n';
  free(arr);
  return 0;
}
