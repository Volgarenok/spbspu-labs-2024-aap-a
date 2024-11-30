#include <iostream>
#include <input_cstring.hpp>

int main()
{
  char * real_number = nullptr;
  size_t capacity = 1;
  try
  {
    real_number = petrov::inputCString(std::cin, capacity);
    if (!std::cin || std::cin.eof() || real_number[0] == '\n')
    {
      delete[] real_number;
      std::cerr << "ERROR: Invalid value\n";
      return 1;
    }
    std::clog << real_number;
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "ERROR: Out of memory\n";
    return 1;
  }
  delete[] real_number;
}
