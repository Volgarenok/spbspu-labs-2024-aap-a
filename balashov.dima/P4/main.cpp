#include <iostream>
#include "processingString.hpp"

int main()
{
  size_t capacity = 5;
  char * line = reinterpret_cast<char*>(malloc(sizeof(char) * (capacity)));
  line = balashov::enteringLine(capacity);
  if(line == nullptr)
  {
    free(line);
    std::cerr << "Memory was not allocated\n";
    return 1;
  }
  if (line[0] == '\0')
  {
    free(line);
    std::cerr << "The absence of a line\n";
    return 1;
  }
  std::cout << balashov::removeSpaces(line) << "\n";
  free(line);
  return 0;
}
