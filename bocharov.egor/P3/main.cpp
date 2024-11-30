#include <iostream>
#include <fstream>
#include "matrix.h"
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
  if (!input.is_open())
  {
    std::cerr << "Failed to open input file\n";
    return 1;
  }
  std::ofstream output(argv[3]);
  if (!output.is_open())
  {
    std::cerr << "Failed to open output file\n";
    return 1;
  }
  size_t rows = 0, cols = 0;
  input  >> rows >> cols;
  if (!input)
  {
    std::cerr << "Input size fail\n";
    return 2;
  }
  constexpr size_t fixed_size = 10000;
  if ((rows * cols) == 0)
  {
    output << rows << " " << cols;
    output << "0\n";
    return 0;
  }
  int fixed_matrix[fixed_size] = {};
  int * matrix = nullptr;
  int * dynamic_matrix = nullptr;
  size_t read = 0;
  if (number == 1)
  {
    if ((rows * cols) > fixed_size)
    {
      std::cerr << "The matrix is too large\n";
      return 2;
    }
    matrix = fixed_matrix;
  }
  else
  {
    try
    {
      dynamic_matrix = new int[rows * cols];
      matrix = dynamic_matrix;
    }
    catch (const std::bad_alloc & e)
    {
      delete[] dynamic_matrix;
      std::cerr << "No memory is allocated for the array\n";
      return 2;
    }
  }
  if (!(bocharov::input_matrix(input, matrix, rows, cols, read)) || (read != (rows * cols)))
  {
    delete[] dynamic_matrix;
    std::cerr << "Input error\n";
    return 2;
  }
  bocharov::change_matrix(matrix, rows, cols);
  bocharov::output_matrix(output, matrix, rows, cols);
  output << bocharov::find_local_maximum(matrix, rows, cols) << "\n";
  std::cout << "\n";
  delete[] dynamic_matrix;
  return 0;
}
