#include "functions.hpp"

int main()
{
  const char * str2 = "def ";
  char * str1 = nullptr;
  try
  {
    str1 = smirnov::getLine(std::cin, '\n');
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }
  if (str1[0] == '\n')
  {
    delete[] str1;
    std::cerr << "Error: empty string\n";
    return 1;
  }
  str1 = smirnov::uniString(str1, str2);
  size_t i = 0;
  while (str1[i] != '\0')
  {
    std::cout << str1[i++];
  }
  std::cout << "\n";
  delete[] str1;
}
