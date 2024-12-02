#include <inputString.hpp>
#include "isRealNumber.hpp"

int main()
{
  size_t capacity = 5;
  char * line = balashov::enteringLine(std::cin, capacity);
  if (line == nullptr)
  {
    std::cerr << "Memory was not allocated\n";
    return 1;
  }
  if (line[0] == '\0')
  {
    free(line);
    std::cerr << "The absence of a line\n";
    return 1;
  }
  std::cout << std::boolalpha << balashov::isFloatingPointLiteral(line) << "\n";
  free(line);
  return 0;
}
