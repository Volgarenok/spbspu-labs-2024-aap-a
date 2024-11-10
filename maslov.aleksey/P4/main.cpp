#include <iostream>
#include "stringManipulator.hpp"

int main()
{
  char * string1 = nullptr;
  try
  {
    string1 = maslov::inputLine(std::cin, '\n');
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }
  const char * string2 = "#f_haRt&$.j)~-+*:@3x";
  std::cout << maslov::excludeCharacters(string1, string2) << "\n";
  delete[] string1;
}
