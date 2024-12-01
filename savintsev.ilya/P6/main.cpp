#include <iostream>
#include <newlineterminatedstr.h>
#include "checkuniquechars.h"

int main()
{
  char * line = savintsev::inputNewlineTerminatedStr(std::cin);
  if (line == nullptr)
  {
    std::cerr << "Failure to allocate memory\n";
    return 1;
  }
  if (line[0] == '\0')
  {
    std::cerr << "No characters to convert\n";
    delete[] line;
    return 1;
  }
  std::cout << std::boolalpha << savintsev::isExpression(line) << '\n';
  delete[] line;
  return 0;
}
