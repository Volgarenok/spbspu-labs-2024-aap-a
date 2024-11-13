#include <iostream>
#include "processingString.hpp"

int main()
{
  size_t capacity = 5;
  char * line = reinterpret_cast<char*>(malloc(sizeof(char) * (capacity)));
  if (line == nullptr)
  {
    free(line);
    std::cerr << "Memory was not allocated\n";
    return 1;
  }

  try
  {
    line = balashov::enteringLine(capacity);
  }
    catch(const std::bad_alloc& e)
  {
    free(line);
    std::cerr << "Memory was not allocated\n";
    return 1;
  }
  std::cout << balashov::removeSpaces(line) << "\n";
  free(line);
  return 0;
}
