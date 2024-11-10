#include "string.hpp"

int main()
{
  try
  {
    char * str = mozhegova::inputString(std::cin, '\n');
  }
  catch(const std::bad_alloc & e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }
}