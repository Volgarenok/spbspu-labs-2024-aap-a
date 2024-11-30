#include <iostream>
#include <stdexcept>
#include <getline.hpp>
#include "is_real_number.hpp"

int main()
{
  char* dynamicString = nullptr;
  try
  {
    dynamicString = maslevtsov::getline(std::cin);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  if (dynamicString[0] == '\0')
  {
    delete[] dynamicString;
    std::cerr << "Error: input is empty\n";
    return 1;
  }

  std::cout << std::boolalpha << maslevtsov::isRealNumber(dynamicString);
  std::cout << '\n';

  delete[] dynamicString;
}
