#include <iostream>
#include <string_input.hpp>
#include "is_equasion.hpp"

int main()
{
  char* str = rychkov::getline(std::cin);
  if (std::cin.fail())
  {
    std::cerr << "Failed to read string\n";
    free(str);
    return 1;
  }
  if (std::cin.eof())
  {
    std::cerr << "there is no input string\n";
    free(str);
    return 1;
  }
  if (*str == '\0')
  {
    std::cerr << "Input string is empty\n";
    free(str);
    return 1;
  }

  std::cout << std::boolalpha << rychkov::isEquasion(str) << '\n';
  free(str);
}
