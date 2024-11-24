#include <iostream>
#include "getString.h"
#include "latinRemove.h"

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
    return 1;
  }
  if (str[0] == '\0')
  {
    std::cerr << "ERROR: Input was incorrect!\n";
    delete[] str;
    return 1;
  }
  std::cout << aleksandrov::latinRemove(str) << "\n";
  delete[] str;
}

