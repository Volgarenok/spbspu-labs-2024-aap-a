#include <iostream>
#include <cstring>
#include "fu_string.h"
#include "functions.h"

int main()
{
  char* str = nullptr;
  if (hismatova::getLine(&str))
  {
    std::cerr << "get line failed!\n";
    return 1;
  }
  size_t position = 0;
  if (hismatova::isValidString(str, position) && position == std::strlen(str))
  {
    std::cout << "true\n";
  }
  else
  {
    std::cout << "false\n";
  }
  free(str);
  return 0;
}
