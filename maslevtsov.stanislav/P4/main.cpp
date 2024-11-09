#include <iostream>
#include "string_functions.hpp"

int main()
{
  constexpr char constString[25] = "~9R hg,3hX i%htQ/K*Y.35T";
  char* dynamicString = nullptr;
  std::size_t stringCapacity = 10;

  try
  {
    dynamicString = new char[stringCapacity + 1];
  }
  catch(const std::bad_alloc& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }

  maslevtsov::getline(std::cin, dynamicString, stringCapacity, '\n');

  std::cout << maslevtsov::isSameSymbols(constString, dynamicString);
  std::cout << '\n';
  delete[] dynamicString;
}
