#include <iostream>
#include <dynamicstrings.h>
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
  int pos = 0;
  std::cout << savintsev::isExpression(line, pos) << '\n';
  return 0;
}
