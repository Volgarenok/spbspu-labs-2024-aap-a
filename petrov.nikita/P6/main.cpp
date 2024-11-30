#include <iostream>
#include <input_cstring.hpp>

int main()
{
  char * real_number = nullptr;
  size_t capacity = 1;
  try
  {
    real_number = petrov::inputCString(std::cin, capacity);
    std::clog << real_number;
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "ERROR: Out of memory\n";
    return 1;
  }
}
