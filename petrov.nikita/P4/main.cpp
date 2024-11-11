#include "making_new_cstring.hpp"

int main()
{
  char * cstring_1 = nullptr;
  std::noskipws(std::cin);
  try
  {
    petrov::inputCSring(std::cin, cstring_1);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "ERROR: Out of memory\n";
    return 1;
  }
}
