#include <iostream>
#include <fstream>
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

  std::ifstream input(argv[2]);
  size_t m = 0, n = 0;
  input >> m >> n;
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
  size_t read = 0;
  if (!mozhegova::inputMatrix(input, t, m, n, read))
  {
    std::cerr << "Invalid matrix element\n";
    return 2;
  }

  if (argv[1] == "1")
  {
    int arr[10000] = {};
    int * v = arr;
  }
  else
  {
    int * v = mozhegova::convert(t, m, n);
  }
}
