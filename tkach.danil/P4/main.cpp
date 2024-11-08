#include <iostream>
#include "strfunc.h"

int main()
{
  size_t capacity = 7;
  char* str = reinterpret_cast<char*>(malloc(sizeof(char) * (capacity)));
  if (str == nullptr)
  {
    std::cerr << "Memory\n";
    return 1;
  }
  try{
    tkach::inputStr(std::cin, str, capacity);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Memory\n";
    return 1;
  }
  std::cout << str << "\n";
  return 0;
}
