#include <iostream>
#include "stringManipulator.hpp"

int main()
{
  char * string1 = maslov::inputLine(std::cin, '\n');
  if (string1 == nullptr)
  {
    return 1;
  }
  const char * string2 = "abc"; //изменить на более сложный
  std::cout << maslov::excludeCharacters(string1, string2) << "\n";
  delete[] string1;
}
