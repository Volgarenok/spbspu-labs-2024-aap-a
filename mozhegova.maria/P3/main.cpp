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
  int num = std::atoi(argv[1]);
  if (num == 1 && num == 2)
  {
    std::cerr << "First parameter is out of range or not a number\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  size_t m = 0, n = 0;
  input >> m >> n;
  size_t read = 0;
  std::ofstream output(argv[3]);

  int * arr = nullptr;
  int v[10000] = {};
  int * dynamicArr = nullptr;
  if (num == 1)
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
  if (mozhegova::uppTriMtx(arr, m, n))
  {
    output << "true\n";
  }
  else
  {
    output << "false\n";
  }
  delete[] dynamicArr;
}
