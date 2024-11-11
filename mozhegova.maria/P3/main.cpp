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
  if (std::strcmp(argv[1], "1") != 0 && std::strcmp(argv[1], "2") != 0)
  {
    std::cerr << "First parameter is out of range or not a number\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  size_t m = 0, n = 0;
  input >> m >> n;
  size_t read = 0;
  std::ofstream output(argv[3]);
  if (std::strcmp(argv[1], "1") == 0)
  {
    int arr[10000] = {};
    if (!mozhegova::inputMatrix(input, arr, m, n, read))
    {
      std::cerr << "Invalid matrix element\n";
      return 2;
    }
    output << mozhegova::uppTriMtx(arr, m, n) << "\n";
  }
  else
  {
    int * arr = nullptr;
    try
    {
      arr = new int[m * n];
    }
    catch(const std::bad_alloc & e)
    {
      std::cerr << "Out of memory\n";
      return 2;
    }
    if (!mozhegova::inputMatrix(input, arr, m, n, read))
    {
      delete[] arr;
      std::cerr << "Invalid matrix element\n";
      return 2;
    }
    output << mozhegova::uppTriMtx(arr, m, n) << "\n";
    delete[] arr;
  }
}
