#include <iostream>
#include "getline.hpp"

int main()
{
  constexpr char stop = "\n";
  try
  {
    char * line = getline(std::cin, stop);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Not enough memory\n";
    return 1;
  }

}
