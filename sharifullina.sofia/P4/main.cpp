#include <iostream>
#include "shrSym_uniTwo.hpp"

int main()
{
  const char str2[] = "def ";
  char * str1 = nullptr;
  char* res = nullptr;
  constexpr size_t new_size = 255;
  try
  {
    res = new char[new_size];
  }
  catch (const std::bad_alloc& e)
  {
    delete[] str1;
    std::cerr << "Out of memory\n";
    return 1;
  }
  try
  {
    str1 = sharifullina::inputString(std::cin, '\n');
  }
  catch (const std::bad_alloc & e)
  {
    delete[] res;
    std::cerr << "Out of memory\n";
    return 1;
  }
  if (str1[0] == '\0')
  {
    delete[] str1;
    delete[] res;
    std::cerr << "Empty input\n";
    return 2;
  }

  std::cout << sharifullina::shrSym(str1, str2, res) << '\n';
  std::cout << sharifullina::uniTwo(str1, str2, res) << '\n';

  delete[] str1;
  delete[] res;
  return 0;
}
