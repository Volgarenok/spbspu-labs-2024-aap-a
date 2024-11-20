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
  int int_argv1 = 0;
  const char *correct = abramov::isCorrect(argv[1], int_argv1);
  if (correct[0] != '\0')
  {
    std::cerr << correct;
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
  try
  {
    matrix = new int[m * n];
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Memory fail\n";
    return 2;
  }
  int *new_mtx = nullptr;
  int nums[10000] = {};
  try
  {
    if (int_argv1 == 1)
    {
      new_mtx = abramov::getMatrix(input, nums, m, n, read, count);
    }
    else if (int_argv1 == 2)
    {
      new_mtx = abramov::getMatrix(input, matrix, m, n, read, count);
    }
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << e.what();
    delete[] matrix;
    return 1;
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << e.what();
    delete[] matrix;
    return 2;
  }
  std::ofstream output(argv[3]);
  abramov::spiralChangeMatrix(new_mtx, count);
  abramov::outputMatrix(output, new_mtx, count);
  delete[] matrix;
  delete[] new_mtx;
}
