#include <iostream>
#include <processLine.hpp>
#include "checkLineOnFloat.hpp"

int main()
{
  char * line = krylov::inputLine(std::cin);
  if (line == nullptr)
  {
    std::cerr << "Memory allocation failure!\n";
    return 1;
  }
  if (line[0] == '\0')
  {
    std::cerr << "The line is empty!\n";
    delete[] line;
    return 1;
  }
  std::cout << std::boolalpha << krylov::isFloatNumber(line);
  std::cout << '\n';

  delete[] line;
}
