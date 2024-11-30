#include <iostream>
#include <processLine.hpp>
#include "replaceLetters.hpp"

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
  constexpr char oldSubstring = 'c';
  constexpr char newSubstring = 'b';
  std::cout << krylov::replaceLetters(line, oldSubstring, newSubstring);
  std::cout << "\n";
  delete[] line;
}
