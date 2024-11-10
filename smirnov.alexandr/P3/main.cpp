#include <iostream>
#include <cctype>
#include <cstdlib>
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
  int num = std::atoi(argv[1]);
  if (num != 1 && num != 2)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  for (int i = 0; argv[1][i] != '\0'; ++i)
  {
    if (!std::isdigit(argv[1][i]))
    {
      std::cerr << "First parameter is not a number\n";
    }
  }
  std::ifstream input(argv[2]);
  size_t rows = 0;
  size_t columns = 0;
  input >> rows >> columns;
  if (!input)
  {
    std::cerr << "Invalid matrix dimensions\n";
    return 2;
  }
  std::ofstream output(argv[3]);
  if (num == 1)
  {
    constexpr size_t size = 10000;
    int matrix[size] = {0};
    if (!smirnov::inputMatrix(input, matrix, rows, columns))
    {
      std::cerr << "Input error\n";
      return 2;
    }
    smirnov::lft_top_clk(matrix, rows, columns);
    smirnov::lft_top_clkOutput(output, matrix, rows, columns);
    smirnov::lwr_tri_mtx(matrix, rows, columns);
    smirnov::lwr_tri_mtxOutput(output, matrix, rows, columns);
  }
  else
  {
    int * matrix = nullptr;
    try
    {
      matrix = new int[rows * columns];
    }
    catch (const std::bad_alloc & e)
    {
      std::cerr << "Out of memory\n";
      delete[] matrix;
      return 1;
    }
    if (!smirnov::inputMatrix(input, matrix, rows, columns))
    {
      std::cerr << "Input error\n";
      delete[] matrix;
      return 2;
    }
    smirnov::lft_top_clk(matrix, rows, columns);
    smirnov::lft_top_clkOutput(output, matrix, rows, columns);
    smirnov::lwr_tri_mtx(matrix, rows, columns);
    smirnov::lwr_tri_mtxOutput(output, matrix, rows, columns);
    delete[] matrix;
  }
}
