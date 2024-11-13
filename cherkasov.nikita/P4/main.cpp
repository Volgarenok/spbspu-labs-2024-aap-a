#include <iostream>
#include <cstddef>
#include <cstring>
#include <ios>
#include "string.h"

int main()
{
  try
  {
    char * line = cherkasov::inpputLine(std::cin);
    if (line == nullptr)
    {
      std::cerr << "Memory allocation fail\n";
      return 1;
    }

  if (line[0] == '\0')
  {
    std::cerr << "The line is empty!\n";
    delete[] line;
    return 1;
  }

  std::size_t size = std::strlen(line);
  char * result = cherkasov::getString(line, size);

  if (result)
  {
    std::cout << result << "\n";
    delete[] result;
  }

  delete[] line;
  }
    catch (const std::exception& e)
    {
      std::cerr << "An exception " << e.what() << "\n";
      return 1;

  return 0;
}
}
