#include <iostream>
#include "matrix.hpp"

int main(int argc, char ** argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  if (mozhegova::isNumber(argv[1]) && argv[1] != "1" && argv[1] != "2")
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  if (!mozhegova::isNumber(argv[1]))
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }

  size_t m = 0, n = 0;
  int ** t = nullptr;
  try
  {
    t = mozhegova::createMatrix(m, n);
  }
  catch(const std::bad_alloc & e)
  {
    std::cerr << "Out of memory\n";
    return 2;
  }
  
}
