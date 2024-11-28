#include <iostream>
#include <stringInput.hpp>
#include "grammarChecker.hpp"

int main()
{
  char * string = nullptr;
  try
  {
    string = maslov::inputLine(std::cin, '\n');
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }
  if (string[0] == '\0')
  {
    delete[] string;
    std::cerr << "Input string is empty\n";
    return 1;
  }
  std::cout << std::boolalpha;
  std::cout << maslov::isExpression(string) << "\n";
  delete[] string;
}
