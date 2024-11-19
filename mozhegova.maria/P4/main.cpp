#include <iostream>
#include <inputstring.hpp>
#include "string.hpp"

int main()
{
  char * str = nullptr;
  try
  {
    str = mozhegova::inputString(std::cin, '\n');
  }
  catch(const std::exception& e)
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
  char * result = mozhegova::spcRmv(str);
  for (size_t i = 0; result[i] != '\0'; i++)
  {
    std::cout << result[i];
  }
  std::cout << '\n';
  delete[] str;
}
