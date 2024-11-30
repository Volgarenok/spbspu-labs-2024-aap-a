#include <iostream>
#include "making_new_cstring.hpp"

int main()
{
  char * cstring_1 = nullptr;
  size_t capacity = 1;
  const char cstring_2[10] = "ls)2)!19 ";
  char * new_cstring = nullptr;
  try
  {
    cstring_1 = petrov::inputCString(std::cin, capacity);
    if (!std::cin || std::cin.eof() || cstring_1[0] == '\n')
    {
      delete[] cstring_1;
      std::cerr << "ERROR: Invalid value\n";
      return 1;
    }
    capacity += sizeof(cstring_2) / sizeof(char) - 1;
    new_cstring = new char[capacity + 1];
    new_cstring = petrov::combineFirstCStrAndDigitsFromSecond(new_cstring, cstring_1, cstring_2);
  }
  catch (const std::bad_alloc & e)
  {
    delete[] cstring_1;
    std::cerr << "ERROR: Out of memory\n";
    return 1;
  }
  std::cout << new_cstring << "\n";
  delete[] cstring_1;
  delete[] new_cstring;
}
