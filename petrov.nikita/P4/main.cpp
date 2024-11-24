#include <iostream>
#include "making_new_cstring.hpp"

int main()
{
  char * cstring_1 = nullptr;
  const char cstring_2[10] = "ls)2)!19 ";
  size_t length_1 = 0;
  const size_t length_2 = sizeof(cstring_2) / sizeof(char) - 1;
  std::noskipws(std::cin);
  char * new_cstring = nullptr;
  try
  {
    cstring_1 = petrov::inputCSring(cstring_1, length_1);
    if (!std::cin || std::cin.eof() || cstring_1[0] == '\n')
    {
      delete[] cstring_1;
      std::cerr << "ERROR: Invalid value\n";
      return 1;
    }
    new_cstring = petrov::makeNewCStringOutOfTwo(new_cstring, cstring_1, cstring_2, length_1, length_2);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "ERROR: Out of memory\n";
    return 1;
  }
  std::cout << new_cstring << "\n";
  delete[] cstring_1;
  delete[] new_cstring;
}
