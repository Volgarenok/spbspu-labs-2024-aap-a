#include "matrix.h"
#include <iostream>
#include <fstream>
#include <cstddef>
#include <stdexcept>
#include <cstdlib>
namespace bocharov
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
  long int check_number(const char* const argv1)
  {
    char* endptr = nullptr;
    long int number = std::strtol(argv1, std::addressof(endptr), 10);
    if (*endptr != '\0')
    {
      throw std::logic_error("First parameter is not a number");
    }
    else if (number < 1 || number > 2)
    {
      throw std::logic_error("First parameter is out of range");
    }
    return number;
  }
}
int main(int argc, char ** argv)
{
  long int number = 0;
  try
  {
    bocharov::check_argc(argc);
    number = bocharov::check_number(argv[1]);
  }
  catch (const std::logic_error & e)
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
  input  >> rows >> cols;
  if (!input.good())
  {
    std::cerr << "Input size fail\n";
    return 2;
  }
  const size_t fixed_size = 10000;
  int fixed_matrix[fixed_size] = {};
  int * final_matrix = nullptr;
  int * dynamic_matrix = nullptr;
  if (number == 1)
  {
    final_matrix = fixed_matrix;
  }
  else
  {
    try
    {
      dynamic_matrix = new int[rows * cols];
      final_matrix = dynamic_matrix;
    }
    catch (const std::bad_alloc & e)
    {
      delete[] dynamic_matrix;
      std::cerr << "No memory is allocated for the array\n";
      return 1;
    }
  }
  if (!(bocharov::input_matrix(input, final_matrix, rows, cols)))
  {
    delete[] dynamic_matrix;
    std::cerr << "Input error\n";
    return 2;
  }
  bocharov::matrix_replace(final_matrix, rows, cols);
  bocharov::output_matrix(output, final_matrix, rows, cols);
  std::cout << "\n";
  delete[] dynamic_matrix;
}
