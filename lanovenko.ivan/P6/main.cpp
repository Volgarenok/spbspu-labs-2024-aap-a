#include <iostream>
#include <strinput.h>
#include "string_check.h"
int main()
{
  char* str = lanovenko::input_string(std::cin, '\n');
  if (str == nullptr)
  {
    std::cerr << "Error! An attempt was made to access a row that is nullptr" << '\n';
    return 1;
  }
  if (str[0] == '\0')
  {
    delete[] str;
    std::cerr << "Line is empty!" << '\n';
    return 1;
  }
  std::cout << std::boolalpha << lanovenko::is_valid_float_string(str) << '\n';
  delete[] str;
}
