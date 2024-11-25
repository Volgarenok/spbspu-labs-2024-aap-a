#include <iostream>
#include "making_new_cstring.hpp"

int main()
{
  char * cstring_1 = nullptr;
  size_t capacity = 1;
  const char cstring_2[10] = "ls)2)!19 ";
  char * new_cstring = nullptr;
  char * numbers = nullptr;
  try
  {
    cstring_1 = petrov::inputCString(std::cin, capacity);
    if (!std::cin || std::cin.eof() || cstring_1[0] == '\n')
    {
      delete[] cstring_1;
      std::cerr << "ERROR: Invalid value\n";
      return 1;
    }
    numbers = petrov::makeNumberArray(cstring_2, capacity);
    new_cstring = petrov::allocateMemoryForNewCString(capacity);
    new_cstring = petrov::makeNewCStringOutOfTwo(new_cstring, cstring_1, numbers);
  }
  catch (const std::bad_alloc & e)
  {
    if (cstring_1 != nullptr)
    {
      delete[] cstring_1;
    }
    else if (numbers != nullptr)
    {
      delete[] cstring_1;
      delete[] numbers;
    }
    std::cerr << "ERROR: Out of memory\n";
    return 1;
  }
  std::cout << new_cstring << "\n";
  delete[] cstring_1;
  delete[] numbers;
  delete[] new_cstring;
}
