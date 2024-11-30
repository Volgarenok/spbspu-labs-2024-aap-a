#include <string_utils.h>
#include <ios>
#include <iostream>
#include "vocab.h"

int main()
{
  char* str = nullptr;
  constexpr size_t max_size = 100;
  constexpr char stop = '\n';
  size_t read = 0;

  try
  {
    if (!demehin::getString(std::cin, &str, stop, max_size, read))
    {
      std::cerr << "input error\n";
      delete[] str;
      return 1;
    }
  }
  catch (const std::bad_alloc& e)
  {
    if (read == 0)
    {
      std::cerr << "Out of memory\n";
      return 1;
    }
    else
    {
      std::cerr << "String expansion failed\n";
    }
  }

  std::cout << std::boolalpha << (demehin::isExpr(str) != nullptr) << "\n";
  delete[] str;

}
