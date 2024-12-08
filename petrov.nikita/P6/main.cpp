#include <iostream>
#include <input_cstring.hpp>
#include "is_real_number.hpp"

int main()
{
  char * maybe_real_number = nullptr;
  size_t capacity = 1;
  try
  {
    maybe_real_number = petrov::inputCString(std::cin, capacity);
    if (maybe_real_number[0] == '\n' || *maybe_real_number == '0')
    {
      delete[] maybe_real_number;
      std::cerr << "ERROR: Empty input\n";
      return 1;
    }
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "ERROR: Out of memory\n";
    return 2;
  }
  std::cout << std::boolalpha << petrov::isRealNumber(maybe_real_number) << "\n";
  delete[] maybe_real_number;
}
