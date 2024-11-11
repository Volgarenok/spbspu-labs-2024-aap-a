#include <iostream>
#include "making_new_cstring.hpp"

int main()
{
  char * cstring_1 = nullptr;
  const char cstring_2[10] = "kf 1 lsa7";
  size_t length_1 = 0;
  const size_t length_2 = sizeof(cstring_2) / sizeof(char);
  std::noskipws(std::cin);
  char * new_cstring = nullptr;
  try
  {
    if (!petrov::inputCSring(std::cin, cstring_1, length_1))
    {
      std::cerr << "ERROR: Invalid value\n";
      return 2;
    }
    petrov::makeNewCStringOutOfTwo(new_cstring, cstring_1, cstring_2, length_1, length_2); 
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "ERROR: Out of memory\n";
    return 1;
  }
  size_t i = 0;
  while (new_cstring[i] != '\0')
  {
    std::cout << new_cstring[i];
  }
  std::cout << "\n";
}
