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
  int numIsOne = std::strcmp(argv[1], "1");
  int numIsTwo = std::strcmp(argv[1], "2");
  if (numIsOne != 0 && numIsTwo != 0)
  {
    std::cerr << "First parameter is out of range or not a number\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  size_t m = 0, n = 0;
  input >> m >> n;
  size_t read = 0;

  int * arr = nullptr;
  int v[10000] = {};
  int * dynamicArr = nullptr;
  if (numIsOne == 0)
  {
    arr = v;
  }
  else
  {
    try
    {
      dynamicArr = new int[m * n];
    }
    catch (const std::bad_alloc & e)
    {
      std::cerr << "Out of memory\n";
      return 2;
    }
    arr = dynamicArr;
  }
  if (!mozhegova::inputMatrix(input, arr, m, n, read))
  {
    std::cerr << "Invalid matrix element\n";
    delete[] dynamicArr;
    return 2;
  }
  std::ofstream output(argv[3]);
  output << std::boolalpha << mozhegova::uppTriMtx(arr, m, n) << '\n';
  delete[] dynamicArr;
}
