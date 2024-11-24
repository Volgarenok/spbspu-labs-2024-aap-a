#include <iostream>

#include <memf.hpp>
#include <string_input.hpp>

#include "string_analysis.hpp"

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

  std::cout << (rychkov::findDigitsRepeatsCount(str) != 0 ? 1 : 0) << '\n';
  free(str);
}
