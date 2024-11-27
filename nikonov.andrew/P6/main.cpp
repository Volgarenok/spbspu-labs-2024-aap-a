#include <iostream>
#include <dynamicArray.hpp>
#include "string_check.hpp"
int main()
{
  size_t capacity = 1;
  const char* arr = nikonov::getLine(std::cin, capacity);
  if (!nikonov::is_float(arr))
  {
    std::cout << "NAH\n";
  }
  else
  {
    std::cout << "YEAH\n";
  }
}
