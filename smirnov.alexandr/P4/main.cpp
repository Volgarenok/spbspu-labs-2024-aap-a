#include "functions.hpp"

int main()
{
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
  if (str1[0] == '\0')
  {
    delete[] str1;
    std::cerr << "Error: empty string\n";
    return 1;
  }
  const char * str2 = "def ";
  char * string = smirnov::uniString(str1, str2);
  std::cout << string << "\n";
  delete[] string;
  delete[] str1;
}
