#include <ios>
#include <iostream>
#include <getString.h>
#include "floatLiteralCheck.h"

int main()
{
  char* str = nullptr;
  try
  {
    str = aleksandrov::getString(std::cin);
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
  if (str[0] == '\0')
  {
    std::cerr << "ERROR: Input was incorrect!\n";
    delete[] str;
    return 1;
  }
  std::cout << std::boolalpha << aleksandrov::isFloatLiteral(str) << "\n";
  delete[] str;
}
