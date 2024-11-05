#include <iostream>
#include <fstream>
#include <cstring>
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

  for (int i = 0; i < argc; i++)
  {
    std::cout << argv[i] << "\n"
  }

  if (sharifullina::isNumber(argv[1] && std::strcmp(argv[1], "1") != 0 && std::strcmp(argv[1], "2") != 0)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }

  if (!sharifullina::isNumber(argv[1]))
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  size_t m = 0, n = 0;
  input >> m >> n;
  if (!input)
  {
    std::cerr << "Rows or columns are not a number\n";
    return 2;
  }
  int ** t = nullptr;
  try
  {
    t = sharifullina::inMatrix(m, n);
  }
  catch(const std::bad_alloc & e)
  {
    std::cerr << "Out of memory\n";
    return 2;
  }

  size_t read = 0;
  if (!sharifullina::inputMatrix(input, t, m, n, read))
  {
    std::cerr << "Invalid matrix element\n";
    sharifullina::destroy(t, m);
    return 2;
  }
  output << sharifullina::maxSumOfDiag(t, m, n) << "\n";
  sharifullina::destroy(t, m);
}
