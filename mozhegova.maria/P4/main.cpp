#include <strinput.hpp>
#include "strmanipulator.hpp"

int main()
{
  char * str = nullptr;
  try
  {
    str = mozhegova::inputString(std::cin, '\n');
  }
  catch (const std::exception& e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }
  if (str[0] == '\0')
  {
    delete[] str;
    std::cerr << "Empty input\n";
    return 1;
  }
  std::cout << mozhegova::spcRmv(str) << '\n';
  delete[] str;
}
