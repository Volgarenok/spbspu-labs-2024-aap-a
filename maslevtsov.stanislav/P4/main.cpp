#include <iostream>
#include <getline.hpp>
#include "string_processing.hpp"

int main()
{
  constexpr char constString[25] = "~9R hg,3hX i%htQ/K*Y.35T";
  char* dynamicString = nullptr;
  try
  {
    dynamicString = maslevtsov::getline(std::cin);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Error: memory not allocated\n";
    return 1;
  }
  if (dynamicString[0] == '\0')
  {
    delete[] dynamicString;
    std::cerr << "Error: input is empty\n";
    return 1;
  }

  std::cout << maslevtsov::isSameSymbols(constString, dynamicString);
  std::cout << '\n';

  delete[] dynamicString;
}
