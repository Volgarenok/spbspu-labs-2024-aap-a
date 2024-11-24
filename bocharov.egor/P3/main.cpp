#include "matrix.h"
#include <iostream>
#include <fstream>
#include <cstddef>
#include <stdexcept>
#include <cstdlib>
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
    return 1;
  }
  size_t rows = 0, cols = 0;
  input  >> rows >> cols;
  if (!input.good())
  {
    std::cerr << "Input size fail\n";
    return 1;
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
    return 1;
  }
  bocharov::matrix_replace(final_matrix, rows, cols);
  bocharov::output_matrix(output, final_matrix, rows, cols);
  std::cout << "\n";
  delete[] dynamic_matrix;
}
