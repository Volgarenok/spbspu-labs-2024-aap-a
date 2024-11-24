#include <ios>
#include <iostream>
#include <getString.h>
#include "floatLiteralCheck.h"

int main()
{
  char* str = nullptr;
  size_t strSize = 0;
  try
  {
    str = aleksandrov::getString(std::cin, strSize);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "ERROR: Out of memory!\n";
    delete[] str;
    return 1;
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what();
    delete[] str;
    return 1;
  }
  std::cout << std::boolalpha << aleksandrov::isFloatLiteral(str) << "\n";
  delete[] str;
}
