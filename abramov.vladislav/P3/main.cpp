#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "matrix.hpp"

int main(int argc, char **argv)
{
  if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  const int int_argv1 = std::atoi(argv[1]);
  if (std::atoi(argv[1]))
  {
    if (int_argv1 > 2 || int_argv1 < 1)
    {
      std::cerr << "First parameter is out of range\n";
      return 1;
    }
  }
  else
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  size_t m = 0;
  size_t n = 0;
  if (!(input >> m >> n))
  {
    std::cerr << "Wrong input\n";
    return 1;
  }
  size_t read = 0;
  size_t count = 0;
  int *matrix = nullptr;
  int *new_mtx = nullptr;
  if (int_argv1 == 1)
  {
    int nums[10000] = {};
    if (!abramov::inputMatrix(input, nums, m, n, read) || read != m * n)
    {
      std::cerr << "Wrong input\n";
      return 1;
    }
    try
    {
      new_mtx = abramov::toSquare(nums, m, n, count);
    }
    catch (const std::bad_alloc &e)
    {
      std::cerr << "Memory fail\n";
      return 2;
    }
  }
  if (int_argv1 == 2)
  {
    try
    {
      matrix = new int[m * n];
      if (!abramov::inputMatrix(input, matrix, m, n, read) || read != m * n)
      {
        std::cerr << "Wrong input\n";
        delete[] matrix;
        return 1;
      }
      new_mtx = abramov::toSquare(matrix, m, n, count);
    }
    catch (const std::bad_alloc &e)
    {
      std::cerr << "Memory fail\n";
      delete[] matrix;
      delete[] new_mtx;
      return 2;
    }
  }
  std::ofstream output(argv[3]);
  abramov::spiralChangeMatrix(new_mtx, count);
  abramov::outputMatrix(output, new_mtx, count);
  delete[] matrix;
  delete[] new_mtx;
}
