#include <ios>
#include <iostream>
#include <string_utils.h>
#include "is_expr.h"

int main()
{
  char* str = nullptr;
  constexpr size_t max_size = 100;
  constexpr char stop = '\n';
  size_t read = 0;

  try
  {
    demehin::getString(std::cin, &str, stop, max_size, read);
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

  if (read == 0)
  {
    std::cerr << "Emty string\n";
    delete[] str;
    return 1;
  }

  std::cout << std::boolalpha << demehin::isExpression(str) << "\n";
  delete[] str;

}
