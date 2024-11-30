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
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "ERROR: Out of memory\n";
    return 1;
  }
  std::cout << std::boolalpha << petrov::isRealNumber(maybe_real_number) << "\n";
  delete[] maybe_real_number;
}
