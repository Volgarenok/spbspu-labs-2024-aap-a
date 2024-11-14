#include <fstream>
#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <cstdlib>
#include "matrix.h"
namespace alymova
{
  void check_argc(int argc)
  {
    if (argc - 1 > 3)
    {
      throw std::logic_error("Too many arguments");
    }
    if (argc - 1 < 3)
    {
      throw std::logic_error("Not enough arguments");
    }
  }
  long int check_num(const char* const argv1)
  {
    char* endptr = nullptr;
    long int num = std::strtol(argv1, std::addressof(endptr), 10);
    if (*endptr != '\0')
    {
      throw std::logic_error("First parameter is not a number");
    }
    else if (num < 1 || num > 2)
    {
      throw std::logic_error("First parameter is out of range");
    }
    return num;
  }
}
int main(int argc, char** argv)
{
  long int num = 0;
  try
  {
    alymova::check_argc(argc);
    num = alymova::check_num(argv[1]);
  }
  catch (const std::logic_error& e)
  {
    std::cout << e.what() << "\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  if (!output)
  {
    return 2;
  }
  size_t rows = 0, cols = 0;
  input >> rows >> cols;
  if (!input.good())
  {
    std::cerr << "Input size fail\n";
    return 2;
  }
  constexpr size_t static_size = 10000;
  int matrix_fixed[static_size] = {};
  int* matrix = nullptr;
  int* matrix_dynamic = nullptr;
  if (num == 1)
  {
    matrix = matrix_fixed;
  }
  else
  {
    try
    {
      matrix_dynamic = new int[rows * cols];
      matrix = matrix_dynamic;
    }
    catch (const std::bad_alloc& e)
    {
      delete[] matrix_dynamic;
      std::cerr << "Memory not allocated for array\n";
      return 1;
    }
  }
  if (!(alymova::input_matrix(input, matrix, rows, cols)))
  {
    delete[] matrix_dynamic;
    std::cerr << "Input failed\n";
    return 2;
  }
  alymova::change_matrix(matrix, rows, cols);
  alymova::print_matrix(output, matrix, rows, cols);
  std::cout << "\n";
  delete[] matrix_dynamic;
}
