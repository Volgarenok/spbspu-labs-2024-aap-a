#include <iostream>
#include <fstream>
#include <cstdlib>
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
  if (atoi(argv[1]) > 2 || atoi(argv[1]) < 1)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  int nums[10000] = {};
  size_t m = 0;
  size_t n = 0;
  size_t read = 0;
  size_t count = 0;
  if (atoi(argv[1]) == 1)
  {
    if(!(input >> m >> n))
    {
      std::cerr << "Wrong input!\n";
      return 1;
    }
    if (!abramov::input_Matrix(input, nums, m, n, read) || read!=m*n)
    {
      std::cerr << "Wrong input!\n";
      return 1;
    }
    int *new_mtx = nullptr;
    try
    {
      new_mtx = abramov::toSquare(nums, m, n, count);
    }
    catch (const std::bad_alloc &e)
    {
      std::cerr << "Memory fail\n";
      return 2;
    }
    abramov::transform_Matrix(new_mtx, count);
    int *matrix = nullptr;
    try
    {
      matrix = abramov::toSquare(nums, m, n, count);
    }
    catch (const std::bad_alloc &e)
    {
      std::cerr << "Memory fail\n";
      return 2;
    }
    abramov::output_Matrix(output, matrix, count);
    delete[] new_mtx;
    delete[] matrix;
  }
  else if (atoi(argv[1]) == 2)
  {
    if(!(input >> m >> n))
    {
      std::cerr << "Wrong input!\n";
      return 1;
    }
    int *matrix = nullptr;
    try
    {
      matrix = new int[m * n];
    }
    catch (const std::bad_alloc &e)
    {
      std::cerr << "Memory fail\n";
      return 2;
    }
    if (!abramov::input_Matrix(input, matrix, m, n, read) || read!=n*m)
    {
      std::cerr << "Wrong input!\n";
      return 1;
    }
    int *new_mtx = nullptr;
    try
    {
      new_mtx = abramov::toSquare(matrix, m, n, count);
    }
    catch (const std::bad_alloc &e)
    {
      std::cerr << "Memory fail\n";
      return 2;
    }
    abramov::transform_Matrix(new_mtx, count);
    abramov::output_Matrix(output, new_mtx, count);
    delete[] matrix;
    delete[] new_mtx;
  }
}
