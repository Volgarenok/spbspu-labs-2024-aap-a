#include <iostream>
#include "getline.hpp"

int main()
{
  constexpr char stop = "\n";
  try
  {
    char * first_line = brevnov::getline(std::cin, stop);
    char * second_line = brevnov::getline(std::cin, stop);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Not enough memory\n";
    return 1;
  }
  brevnov::finding_common_elements(first_line, second_line);
  return 0;
}
