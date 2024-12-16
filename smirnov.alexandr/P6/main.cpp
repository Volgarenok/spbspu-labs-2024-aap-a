#include <iostream>
#include <getLine.hpp>
#include "checkString.hpp"

int main()
{
  char * string = nullptr;
  try
  {
    string = smirnov::getLine(std::cin, '\n');
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }
  if (string[0] == '\0')
  {
    delete[] string;
    std::cerr << "Error: empty string\n";
    return 1;
  }
  std::cout << std::boolalpha << smirnov::isFloatNumber(string) << "\n";
  delete[] string;
}
