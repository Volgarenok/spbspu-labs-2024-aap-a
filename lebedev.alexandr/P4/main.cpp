#include <iostream>
#include "string.hpp"

int main()
{
  char* str = nullptr;
  try
  {
    str = lebedev::getLine(std::cin, '\n');
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Memory allocation error!\n";
    return 2;
  }
  if (!std::cin)
  {
    std::cerr << "Incorrect input!\n";
    return 1;
  }
  lebedev::removeVowels(str);
  std::cout << str << '\n';
  delete[] str;
  return 0;
}
